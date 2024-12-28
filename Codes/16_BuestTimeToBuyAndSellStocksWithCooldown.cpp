class Solution {
public:

    // TC = O(n)

    int n = -1;
    vector<vector<int>>dp;

    int solve(int i, bool hold, vector<int>&prices){

        if(i>=n) return 0;

        if(dp[i][hold] != INT_MAX) return dp[i][hold];

        if(hold == false){

            return dp[i][hold] = max( solve(i+1, false, prices), -prices[i]+solve(i+1, true, prices) );
        }

        return dp[i][hold] = max( solve(i+1, true, prices), prices[i]+solve(i+2, false, prices) );
    }

    int maxProfit(vector<int>& prices) {
        
        n = prices.size();
        dp.resize(n+1, vector<int>(2, INT_MAX));

        return solve(0, false, prices);
    }
};
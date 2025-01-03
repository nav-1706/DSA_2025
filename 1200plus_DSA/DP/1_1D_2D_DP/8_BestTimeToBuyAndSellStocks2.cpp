class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, vector<int>&prices, bool canSold){

        if(i >= prices.size()) return 0;

        if(dp[i][canSold] != -1) return dp[i][canSold];

        if(canSold == false){ // canBuy only

            return dp[i][canSold] = max(-prices[i] + solve(i+1, prices, !canSold), solve(i+1, prices, canSold));
        }

        return dp[i][canSold] = max(prices[i] + solve(i+1, prices, !canSold), solve(i+1, prices, canSold));
    }

    int maxProfit(vector<int>& prices) {
        
        dp.resize(prices.size()+5, vector<int>(2, -1));

        return solve(0, prices, false);
    }
};
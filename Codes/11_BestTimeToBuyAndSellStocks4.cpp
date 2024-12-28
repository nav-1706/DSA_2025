class Solution {
public:

    vector<vector<vector<int>>>dp;

    int solve(int i, vector<int>&prices, bool canSold, int t ,int k){ // t --> number of transactions compelted

        if(i >= prices.size() || t >= k) return 0;

        if(dp[i][canSold][t] != -1) return dp[i][canSold][t];

        if(canSold == false){ // canBuy only

            return dp[i][canSold][t] = max(-prices[i] + solve(i+1, prices, !canSold, t, k), solve(i+1, prices, canSold, t, k));
        }

        return dp[i][canSold][t] = max(prices[i] + solve(i+1, prices, !canSold, t+1, k), solve(i+1, prices, canSold, t, k));
    }

    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        dp.resize(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return solve(0, prices, false, 0, k);
    }
};
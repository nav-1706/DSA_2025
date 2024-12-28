class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, vector<int>&prices, bool canSale, int fee){

        if(i == prices.size()) return 0;

        if(dp[i][canSale] != -1) return dp[i][canSale];

        if(canSale == false){ // only canBuy

            return dp[i][canSale] = max(-prices[i] + solve(i+1, prices, !canSale, fee), solve(i+1, prices, canSale, fee));
        }

        return dp[i][canSale] = max(prices[i] - fee + solve(i+1, prices, !canSale, fee), solve(i+1, prices, canSale, fee));
    }

    int maxProfit(vector<int>& prices, int fee) {
        
        dp.resize(prices.size()+1, vector<int>(2, -1));
        return solve(0, prices, false, fee);
    }
};
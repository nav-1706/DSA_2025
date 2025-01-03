class Solution {
public:

    vector<int>dp;

    int solve(vector<int>&coins, int amount){

        if(amount == 0) return 0;
        // if(amount < 0) return -1;

        if(dp[amount] != -2) return dp[amount];

        int ways = INT_MAX;
        for(int i=0; i<coins.size(); i++){

            if(coins[i] <= amount){

                int res = solve(coins, amount-coins[i]);

                if(res != -1){
                    ways = min(ways, res);
                }
            }
        }

        if(ways == INT_MAX) return dp[amount] = -1;
        return dp[amount] = 1+ways;
    }

    int coinChange(vector<int>& coins, int amount) {
        
        dp.resize(amount+1, -2);
        return solve(coins, amount);
    }
};
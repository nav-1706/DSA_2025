/*

If we have taken, a coin at idx 'i', then we will not take coins from index 0 to 'i-1' as it would have been already counted in previous recursive call, we will only taken coins from 'i'th index to till last index

If we taken previous indices also, then it will it us all possible *permutations*, we want unique *combinations*

*/

class Solution {
public:

    vector<vector<int>>dp;

    int solve(int amount, vector<int>&coins, int prev_coin_idx){

        if(amount == 0) return 1;
        if(amount < 0) return 0;

        if(dp[amount][prev_coin_idx] != -1) return dp[amount][prev_coin_idx];

        int ways = 0;
        for(int i=prev_coin_idx; i<coins.size(); i++){

            if(amount >= coins[i]){

                ways += solve(amount-coins[i], coins, i);
            }
        }

        return dp[amount][prev_coin_idx] = ways;
    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        dp.resize(amount+1, vector<int>(n+1, -1));
        return solve(amount, coins, 0);
    }
};
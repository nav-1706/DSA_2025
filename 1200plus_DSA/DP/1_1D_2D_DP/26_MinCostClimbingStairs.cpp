class Solution {
public:

    int top_floor_idx = -1;
    vector<int>dp;

    int solve(int i, vector<int>&cost){

        if(i == top_floor_idx) return 0;
        if(i > top_floor_idx) return INT_MAX;

        if(dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(solve(i+1, cost), solve(i+2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        top_floor_idx = cost.size();
        dp.resize(cost.size()+1, -1);

        return min(solve(0, cost), solve(1, cost));
    }
};
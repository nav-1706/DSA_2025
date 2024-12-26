class Solution {
public:

    vector<vector<int>>dp;

    bool solve(int i, vector<int>&stones, int k){ // k --> last jump
        
        if(i == stones.size()-1) return true;

        if(i == 0) return solve(i+1, stones, 1);

        if(dp[i][k] != -1) return dp[i][k];

        bool finalAns = false;
        for(int j = i+1; j<stones.size(); j++){
            
            if(stones[j] == stones[i]+ (k-1)) finalAns = finalAns || solve(j, stones, k-1);
            if(stones[j] == stones[i]+ (k)) finalAns = finalAns || solve(j, stones, k);
            if(stones[j] == stones[i]+ (k+1)) finalAns = finalAns || solve(j, stones, k+1);
        }

        return dp[i][k] = finalAns;
    }

    bool canCross(vector<int>& stones) {
        
        if(stones[1] > 1) return false;

        dp.resize(stones.size()+5, vector<int>(stones.size()+5, -1));
        return solve(0, stones, 0);
    }
};
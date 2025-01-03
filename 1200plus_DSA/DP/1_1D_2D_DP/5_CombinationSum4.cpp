class Solution {
public:

    vector<int>dp;

    int solve(int target, vector<int>nums){

        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];

        int ways = 0;
        for(int i=0; i<nums.size(); i++){

            if(target >= nums[i]) ways += solve(target-nums[i], nums);
        }

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(target+1, -1);
        return solve(target, nums);
    }
};
class Solution {
public:

    int totalSum = 0;
    vector<vector<int>>dp;

    bool solve(int i, int sum, vector<int>&nums){

        if(i == nums.size() && sum == totalSum/2) return true;
        if(i == nums.size() && sum != totalSum/2) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        return dp[i][sum] = ( solve(i+1, sum+nums[i], nums) || solve(i+1, sum, nums) );
    }

    bool canPartition(vector<int>& nums) {
        
        for(auto ele: nums) totalSum += ele;
        if(totalSum % 2 != 0) return false;

        dp.resize(nums.size()+1, vector<int>(totalSum+1, -1));

        return solve(0, 0, nums);
    }
};
// Solved onw my own :)

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(1005, vector<int>(n+1, 1));

        int maxi = INT_MIN;

        for(int i=1; i<n; i++){
            
            for(int j=0; j<i; j++){

                int diff = nums[i]-nums[j];
                dp[diff+500][i] = dp[diff+500][j]+1;

                maxi = max(maxi, dp[diff+500][i]);
            }
        }

        return maxi;
    }
};
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0 || n == 1 || n==2) return 0;
        vector<int>dp(n);

        dp[0] = 0;
        dp[1] = 0;

        // dp[i] ==> Number of arithmatic slices jo ith index par khatam ho rahi hai
        int total = 0;

        for(int i=2; i<n; i++){

            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){

                dp[i] = dp[i-1]+1;
                total += dp[i];
            }

            else dp[i] = 0;
        }

        return total;

        // total = Number of arithmatic slices jo 0-th index par khatam ho rahi hai + 1st index par khatam ho rahi + 2nd par till n-1 index
    }
};
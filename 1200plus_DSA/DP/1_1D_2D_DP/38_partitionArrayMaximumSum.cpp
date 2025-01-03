class Solution {
public:

    vector<int>dp;

    int solve(int i, vector<int>&arr, int k){

        if(i >= arr.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int maxiSum = INT_MIN;
        int max_ele = arr[i];

        for(int j=1; j<=k && i+j-1 < arr.size(); j++){

            max_ele = max(max_ele, arr[i+j-1]);
            maxiSum = max(maxiSum, max_ele*(j)+solve(i+j, arr, k));
        }

        return dp[i] = maxiSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        dp.resize(arr.size()+1, -1);

        return solve(0, arr, k);
    }
};
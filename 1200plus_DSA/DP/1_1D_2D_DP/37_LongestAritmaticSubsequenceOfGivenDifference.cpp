class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp; // Maps value to the length of the longest subsequence ending with that value
        int max_len = 1;

        for (int num : arr) {
            int prev_value = num - difference;
            dp[num] = dp[prev_value] + 1; // Extend the subsequence ending at prev_value
            max_len = max(max_len, dp[num]); // Update the maximum length
        }

        return max_len;
    }
};

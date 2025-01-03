/* ********************* METHOD-1: BOTTOM UP *****************
---------------------------------------------------------------*/

class Solution {
public:

    // Approach: Find longest common subsequence in s and revrse of s

    int longestPalindromeSubseq(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        for(int i=0; i<=n; i++) dp[i][0] = 0; // 1st col -> all element = 0
        for(int j=0; j<=n; j++) dp[0][j] = 0; // 1st row -> all element = 0


        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){

                if(s[i-1] == rev[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }

                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }
};

/* ********************* METHOD-2: BOTTOM UP *****************
---------------------------------------------------------------*/

class Solution {
public:

    // ** Blue Print **

    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n));

        // dp[i][j] --> LPS from index [i : j]

        for(int i=0; i<n; i++) dp[i][i] = 1;

        for(int L = 2; L<=n; L++){

            for(int i=0; i < n-L+1; i++){

                int j = i+L-1;

                if(s[i] == s[j]){

                    dp[i][j] = 2 + dp[i+1][j-1];
                }

                else {

                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};
class Solution {
public:

    vector<vector<int>>dp;

    /*

    bool isPalin(int i, int j, string &s){

        if(i == j || i > j) return true;

        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (s[i] == s[j] && isPalin(i+1, j-1, s));
    }

    */

    string longestPalindrome(string s) {
        
        /*

        ********** METHOD 1 (RECURSION + MEMO) *****************

        dp.resize(s.length()+1, vector<int>(s.length(), -1));

        int maxLen = 0;
        int startIdx = -1;

        for(int i=0; i<s.length(); i++){

            for(int j=i; j<s.length(); j++){

                if(isPalin(i, j, s)){
                    int len = j-i+1;

                    if(len > maxLen){
                        startIdx = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);

        */


        // ************** METHOD 2: BOTTOM-UP --> Blue Print ****************
        
        // dp[i][j] --> true or false --> string[i-th idx : j-th idx] is parildrone or not

        int n = s.length();
        vector<vector<bool>>dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int startIdx  = 0; 

        for(int L = 1; L <= n; L++){

            for(int i=0; i+L-1 < n; i++){

                int j = i+L-1;

                if( L == 1){
                    dp[i][j] = true;
                }

                else if(L == 2){

                    dp[i][j] = (s[i] == s[j]);
                }

                else{

                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }

                if(dp[i][j] && L > maxLen){

                    maxLen = L;
                    startIdx = i;
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};  
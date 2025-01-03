/* ************** METHOD-1: RECUSION DP PRINTING*****************
----------------------------------------------------------------*/

class Solution {
public:

    vector<vector<string>>dp;

    string solve(int i, int j, string&s1, string &s2){

        if(i == s1.length() || j == s2.length()) return "";

        if(s1[i] == s2[j]) return string(1, s1[i]) + solve(i+1, j+1, s1, s2);

        if(dp[i][j] != "*") return dp[i][j];

        string res1 = solve(i+1, j, s1, s2);
        string res2 = solve(i, j+1, s1, s2);

        if(res1.length() < res2.length()) return dp[i][j] = res2;
        return dp[i][j] = res1; 
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        dp.resize(text1.length()+1, vector<string>(text2.length()+1, "*"));
        string ans = solve(0, 0, text1, text2);

        cout<<ans<<endl;
        return ans.length();
    }
};

/* ************** METHOD-2: BOTTOM DP PRINTING*****************
----------------------------------------------------------------*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // state dp[i][j] --> longest commong subsequence of s1(till length i) and s2(till length j), we have to return dp[m][n]

        int m = text1.length();
        int n = text2.length();

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){

            for(int j=1; j<=n; j++){

                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                else{

                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // ** Printing LCS **
        string lcs = "";
        int i = m;
        int j = n;

        while(i > 0 && j > 0){

            if(text1[i-1] == text2[j-1]){
                lcs.push_back(text1[i-1]);

                i--;
                j--;
            }

            else{

                if(dp[i-1][j] > dp[i][j-1]){

                    i--;
                }

                else j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        cout<<lcs;

        return dp[m][n];
    }
};
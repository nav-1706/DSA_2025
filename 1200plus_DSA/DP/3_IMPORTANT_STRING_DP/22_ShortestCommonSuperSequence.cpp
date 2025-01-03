/******************** METHOD-1: BOTTOM-UP PRINTING ***************
---------------------------------------------------------------*/

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();
        
        // dp[i][j] --> shoertest common supersequence for s1(of i lenght) and s2(of j length)
        
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<=m; i++) dp[i][0] = i;
        for(int j=0; j<=n; j++) dp[0][j] = j;
        
        for(int i=1; i<=m; i++){
            
            for(int j=1; j<=n; j++){
                
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                
                else{
                    
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // return dp[m][n];

        string scs = "";

        int i = m;
        int j = n;

        while(i > 0 && j > 0){

            if(s1[i-1] == s2[j-1]){

                scs.push_back(s1[i-1]);
                i--;
                j--;
            }

            else{

                if(dp[i-1][j] < dp[i][j-1]){

                    scs.push_back(s1[i-1]);
                    i--;
                }

                else{
                    scs.push_back(s2[j-1]);
                    j--;
                }
            }
        }

        while(i > 0){
            scs.push_back(s1[i-1]);
            i--;
        }

        while(j > 0){
            scs.push_back(s2[j-1]);
            j--;
        }

        reverse(scs.begin(), scs.end());

        return scs;
    }
};

/******************** METHOD-2: RECURSION **********************
---------------------------------------------------------------*/

class Solution {
public:

    vector<vector<string>>dp;

    string solve(int i, int j, string &str1, string str2){


        if(i == str1.length()) return str2.substr(j);

        if(j == str2.length()) return str1.substr(i);

        if(dp[i][j] != "*") return dp[i][j];

        if(str1[i] == str2[j]) return string(1, str1[i]) + solve(i+1, j+1, str1, str2);

        string s1_taken_s2_left = string(1, str1[i]) + solve(i+1, j, str1, str2);
        string s2_taken_s1_left = string(1, str2[j]) + solve(i, j+1, str1, str2);

        // both left --> included in above two calls, no need to write explicitally

        if(s1_taken_s2_left.length() < s2_taken_s1_left.length()) return dp[i][j] = s1_taken_s2_left;
        return dp[i][j] = s2_taken_s1_left;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        
        dp.resize(str1.length()+1, vector<string>(str2.length()+1, "*"));
        return solve(0, 0, str1, str2);
    }
};
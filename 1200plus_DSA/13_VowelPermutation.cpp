class Solution {
public:

    long long int MOD = 1000000007;
    vector<vector<int>>dp;

    int solve(string &vowel, int i, int n){

        if(n == 1) return 1;
        if(n == 0) return 0;

        if(dp[i][n] != -1) return dp[i][n];

        if(i == 2) {

            int ways = 0;
            for(int k=0; k<vowel.size(); k++){

                if(k == i) continue;
                ways = (ways + (solve(vowel, k, n-1))%MOD)%MOD;
            }

            return dp[i][n] = ways;
        }

        int ways = 0;
        int len = vowel.length();

        if(i-1 >= 0 && i !=4 ) ways = (ways + (solve(vowel, i-1, n-1))%MOD)%MOD;
        ways = (ways +  (solve(vowel, (i+1)%len, n-1))%MOD)%MOD;

        return dp[i][n] = ways;
    }

    int countVowelPermutation(int n) {
        
        string vowel = "aeiou";

        dp.resize(5, vector<int>(n+1, -1));

        int total = 0;
        for(int i=0; i<5; i++){
            total = (total + (solve(vowel, i, n))%MOD)%MOD;
        }

        return total;
    }
};
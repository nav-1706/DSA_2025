class Solution {
public:

    vector<int>dp;

    int solve(int n){

        if(n == 0) return 1;
        if(n == 1 || n == 2) return n;

        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1; i<=n; i++){

            ans += (solve(i-1) * solve(n-i));
        }
        return dp[n] = ans;
    }

    int numTrees(int n) {
        
        dp.resize(n+1, -1);
        return solve(n);
    }
};
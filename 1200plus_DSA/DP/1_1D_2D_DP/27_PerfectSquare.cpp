/*

There is Math solution by using Legendre's three-square theorem & Sum of two squares theorem.

*/

class Solution {
public:

    vector<int>dp;

    int solve(int n){

        if(n == 1 || n == 0) return n;

        if(dp[n] != -1) return dp[n];
        int squ_root = sqrt(n);
        
        int mini = INT_MAX;
        for(int i=1; i<=squ_root; i++){

            mini = min(mini, solve(n-(i*i)));
        }

        return dp[n] = 1+mini;
    }
    
    int numSquares(int n) {
        
        dp.resize(n+1, -1);

        return solve(n);
    }
};
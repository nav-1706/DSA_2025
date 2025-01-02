class Solution {
public:

    long long int MOD = 1000000007;
    vector<vector<int>>dp;

    int solve(int target, int n, int k){ // n --> kitni baari me karna hai, k --> kitne faces hai
    
        if(target == 0 && n == 0) return 1;
        if(target == 0 && n != 0) return 0;
        if(target != 0 && n == 0) return 0;
        if(target < 0) return 0;

        if(dp[target][n] != -1) return dp[target][n];

        long long int ways = 0;
        for(int i=1; i<=k; i++){

            if(target >= i){
                
                ways = (ways + (solve(target-i, n-1,k))%MOD)%MOD;
            }
        }

        return dp[target][n] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        dp.resize(target+1, vector<int>(n+1, -1));
        return solve(target, n, k);   
    }
};
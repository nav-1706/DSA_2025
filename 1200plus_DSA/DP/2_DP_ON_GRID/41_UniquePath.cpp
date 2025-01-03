class Solution {
public:

    int rows; 
    int cols;

    vector<vector<int>>dp;

    int solve(int i, int j){

        if(i == rows-1 && j == cols-1) return 1;
        if(i >= rows || j >= cols) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i+1, j) + solve(i, j+1);
    }

    int uniquePaths(int m, int n) {
        
        rows = m;
        cols = n;

        dp.resize(m+1, vector<int>(n+1, -1));

        return solve(0, 0);
    }
};
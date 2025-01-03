class Solution {
public:

    int n;

    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& matrix){

        if(i == n-1) return matrix[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int path_sum = INT_MAX;

        if(j-1 >= 0) path_sum = min(path_sum, matrix[i][j] + solve(i+1, j-1, matrix));
        if(j+1 < n) path_sum = min(path_sum, matrix[i][j] + solve(i+1, j+1, matrix));
        path_sum = min(path_sum, matrix[i][j] + solve(i+1, j, matrix));

        return dp[i][j] = path_sum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        n = matrix.size();

        int mini = INT_MAX;
        dp.resize(n+1, vector<int>(n+1, INT_MAX));

        for(int col=0; col<n; col++){

            mini = min(mini, solve(0, col, matrix));
        }

        return mini;
    }
};
class Solution {
public:
    
    int n;
    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& grid){
        
        if(dp[i][j] != INT_MAX) return dp[i][j];
        
        if(i == n-1) return dp[i][j] = grid[i][j];

        int path_sum = INT_MAX;

        for(int col = 0; col < n; col++){

            if(col == j) continue;
            path_sum = min(path_sum, grid[i][j] + solve(i+1, col, grid));
        }

        return dp[i][j] = path_sum;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        
        n = grid.size();

        if(n == 1) return grid[0][0];

        dp.resize(n+1, vector<int>(n+1, INT_MAX));

        int mini = INT_MAX;

        for(int col = 0; col < n; col++){

            mini = min(mini, solve(0, col, grid));
        }

        return mini;
    }
};
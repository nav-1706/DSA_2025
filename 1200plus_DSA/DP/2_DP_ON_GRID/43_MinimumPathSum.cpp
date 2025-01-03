class Solution {
public:

    int rows = -1;
    int cols = -1;
    vector<vector<int>>dp;

    int solve(vector<vector<int>>& grid, int i, int j){

        if(i >= rows || j >= cols) return INT_MAX;
        if(i == rows-1 && j == cols-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(solve(grid, i+1, j), solve(grid, i, j+1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();
        dp.resize(rows+1, vector<int>(cols+1, -1));

        return solve(grid, 0, 0);
    }
};
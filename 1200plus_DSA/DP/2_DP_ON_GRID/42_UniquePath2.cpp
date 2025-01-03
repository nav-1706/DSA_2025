class Solution {
public:

    int m = -1;
    int n = -1;

    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& grid){

        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ways = 0;

        if(i+1 < m && grid[i+1][j] == 0){ // moving down

            ways += solve(i+1, j, grid);
        }

        if(j+1 < n && grid[i][j+1] == 0){ // moving right

            ways += solve(i, j+1, grid);
        }

        return dp[i][j] = ways;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[m-1][n-1] == 1) return 0;

        dp.resize(m+1, vector<int>(n+1, -1));

        return solve(0,0, obstacleGrid);
    }
};
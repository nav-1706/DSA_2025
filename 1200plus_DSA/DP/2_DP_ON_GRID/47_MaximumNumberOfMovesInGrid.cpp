class Solution {
public:

    int m; 
    int n;

    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& grid){

        if(j == n-1) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ways = 0;
        if(i-1 >=0 && grid[i-1][j+1] > grid[i][j]) ways = max(ways, 1+ solve(i-1, j+1 ,grid)); 
        if(i+1 < m && grid[i+1][j+1] > grid[i][j]) ways = max(ways, 1+ solve(i+1, j+1 ,grid));
        if(grid[i][j+1] > grid[i][j]) ways = max(ways, 1+ solve(i, j+1 ,grid));

        return dp[i][j] = ways;
    }

    int maxMoves(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        dp.resize(m+1, vector<int>(n+1, -1));

        int total = INT_MIN;
        for(int i=0; i<m; i++){

            total = max(total, solve(i, 0, grid));
        }

        return total;
    }
};
// 

class Solution {
public:

    int m;
    int n;

    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>&grid){

        if(grid[i][j] == -1 && j == 0) return -1; // left wall check
        if(grid[i][j] == 1 && j == n-1) return -1; // right wall check
        if(grid[i][j] == 1 && grid[i][j+1] == -1) return -1; // V check
        if(grid[i][j] == -1 && grid[i][j-1] == 1) return -1; // ^ check

        if(dp[i][j] != -1) return dp[i][j];

        if(i == m-1){

            if(grid[i][j] == 1) return dp[i][j] = j+1;
            return dp[i][j] = j-1;
        }

        if(grid[i][j] == 1) return dp[i][j] = solve(i+1, j+1, grid);

        return dp[i][j] = solve(i+1, j-1, grid);
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        dp.resize(m+1, vector<int>(n+1, -1));

        vector<int>ans(n, -1);

        for(int col = 0; col < n; col++){
            
            ans[col] = solve(0, col, grid);
        }

        return ans;
    }
};
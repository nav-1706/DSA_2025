class Solution {
public:

    int m;
    int n;
    int dp[71][71][71];

    int solve(int r, int c1, int c2, vector<vector<int>>& grid){
        
        if(c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)  return 0;

        if(r == m-1){ // r2 == m-1 --> dono ek saath hi neeche pahuchenge

            if(c1 == c2) return grid[r][c1];
            return grid[r][c1] + grid[r][c2];
        }

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int cherries = 0;
        if(c1 == c2) cherries = grid[r][c1];
        else cherries += grid[r][c1] + grid[r][c2];

        int f1 = solve(r+1, c1-1, c2-1, grid);; // left-left

        int f2 = solve(r+1, c1-1, c2, grid); // left-mid 

        int f3 = solve(r+1, c1-1, c2+1, grid); // left-right

        int f4 = solve(r+1, c1, c2-1, grid); // mid-left

        int f5 = solve(r+1, c1, c2, grid); // mid-mid

        int f6 = solve(r+1, c1, c2+1, grid); // mid-right

        int f7 = solve(r+1, c1+1, c2-1, grid); // right-left

        int f8 = solve(r+1, c1+1, c2, grid); // right-mid

        int f9 = solve(r+1, c1+1, c2+1, grid); // right-right

        cherries += max({f1, f2, f3, f4, f5, f6, f7, f8, f9});
        return dp[r][c1][c2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();   

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n-1, grid);
    }
};
/*
Instead of moving one person from top left to bottom right, and then bottom right to top left, we will move two person from top left to bottom right;

*/

// Previous Solution: O(N^4)

// Also r1+c1 will be always equal to r2+c2 --> we can convert this 4D DP in 3D DP --> O(N^3)

class Solution {
public:

    int n;
    int dp[51][51][51];

    int solve(int r1, int c1, int r2, vector<vector<int>>& grid){

        int c2 = (r1+c1) - r2;

        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;

        if(r1 == n-1 && c1 == n-1) return grid[r1][c1];
        // if(r2 == n - 1 && c2 == n - 1) return grid[r2][c2];
      
        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        int cherries = 0;
        if(r1 == r2 && c1 == c2) cherries += grid[r1][c1];

        else{
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int f1 = solve(r1+1, c1, r2+1,grid); // down, down
        int f2 = solve(r1, c1+1, r2, grid); // right right
        int f3 = solve(r1+1, c1, r2, grid); // down right
        int f4 = solve(r1, c1+1, r2+1,grid); // right down;

        cherries += max({f1, f2, f3, f4});
        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        n = grid.size();

        memset(dp, -1, sizeof(dp));

        int res = solve(0, 0, 0, grid);
        if(res < 0) return 0;

        return res;
    }
};
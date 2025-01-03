// Implement Bottom-Up 2D solution

class Solution {
public:

    int rows;
    int cols;
    long long int MOD = 1000000007;

    vector<vector<int>>dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

    vector<vector<vector<int>>>dp;

    int solve(int i, int j, int moves){

        if(i>=rows || i<0 || j>=cols || j<0){

            // if(moves >= 0) return 1;
            // return 0;
            return 1;
        }

        if(moves == 0) return dp[i][j][moves] = 0;

        if(dp[i][j][moves] != -1) return dp[i][j][moves];

        int ways = 0;
        for(auto d: dir){

            ways = (ways + (solve(i+d[0], j+d[1], moves-1))%MOD)%MOD;
        }

        return dp[i][j][moves] = ways;
        
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        rows = m;
        cols = n;

        dp.resize(rows+1, vector<vector<int>>(cols+1, vector<int>(maxMove+1, -1)));

        return solve(startRow, startColumn, maxMove);
    }
};
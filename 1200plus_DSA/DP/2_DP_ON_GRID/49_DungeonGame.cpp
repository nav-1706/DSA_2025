class Solution {
public:

    int m;
    int n;

    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& grid){

        if(i >= m || j >= n) return 200000; // Ideally very large number, here 200000 is out of constraint of question

        if(i == m-1 && j == n-1){
            if(grid[i][j] >= 0) return 1;
            return -grid[i][j]+1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int minimum_from_right = solve(i, j+1, grid) - grid[i][j];
        if(minimum_from_right <= 0) minimum_from_right = 1;

        int minimum_from_down = solve(i+1, j, grid) - grid[i][j];
        if(minimum_from_down <= 0) minimum_from_down = 1;

        return dp[i][j] = min(minimum_from_right, minimum_from_down);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        m = dungeon.size();
        n = dungeon[0].size();

        dp.resize(m+1, vector<int>(n+1, -1));

        int ans = solve(0, 0, dungeon);
        if(ans <= 0) return 1;
        return ans;
    }
};
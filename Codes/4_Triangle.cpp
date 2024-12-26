class Solution {
public:

    vector<vector<int>>dp;

    int solve(vector<vector<int>>& triangle, int row, int col){

        if(row == triangle.size()) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = (triangle[row][col] + min(solve(triangle, row+1, col), solve(triangle, row+1, col+1)));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        int cols = triangle[rows-1].size();

        dp.resize(rows+5, vector<int>(cols+5, -1));
        return solve(triangle, 0, 0);
    }
};
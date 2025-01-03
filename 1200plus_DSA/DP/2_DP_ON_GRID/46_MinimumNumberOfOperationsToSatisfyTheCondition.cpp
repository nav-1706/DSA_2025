// https://youtu.be/4cEYIggeRDM?si=gl4xujJK_tHPOLV4

/*

Algorithm:
    1. We will try to change the 1st value of every column to every other number possible(not equal to 1st value of left columns)

    2. And then for every value to which we have replace the original value, we will count the number of changes we have to made in that particular columns (as all value in the column should be same)

*/

class Solution {
public:

    int row;
    int col;

    vector<vector<int>>dp; // dp[j][keep] --> minium operations in matrix with colums number [j to last] is we replace all value of that column(as value of elemet just below must be equal for all elements) with value 'keep' 

    int solve(int j, int keep, vector<vector<int>>& grid){
        
        if(j >= col) return 0;

        if(dp[j][keep] != -1) return dp[j][keep];

        int minAns = INT_MAX;
        int cost = 0; // changes made in that colums if we replace it with 'keep'

        for(int i=0; i<row; i++){

            if(grid[i][j] != keep) cost++;
        }


        for(int right_col_option = 0; right_col_option<=9; right_col_option++){

            if(right_col_option == keep) continue; // right_col can't have value equal to keep(i.e value to9 its left)

            minAns = min(minAns, solve(j+1, right_col_option, grid));
        }

        return dp[j][keep] = cost + minAns;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        
        row = grid.size();
        col = grid[0].size();

        dp.resize(col+1, vector<int>(10, -1));

        int mini = INT_MAX;

        for(int keep = 0; keep <= 9; keep++){

            mini = min(mini, solve(0, keep, grid));
        }

        return mini;
    }
};
// O(N^3)

class Solution {
public:

    int n;

    int dp1[102][102];
    vector<vector<vector<int>>>dp2;
    long long int MOD = 1000000007;

    int solve(int i, int j, vector<string>& grid){

        if(i < 0 || j < 0 || grid[i][j] == 'X') return INT_MIN; // in-valid case

        if(i == 0 && j == 0) return 0;

        if(dp1[i][j] != -1) return dp1[i][j];

        // (i-1, j), (i, j-1), (i-1, j-1)

        int upScore = solve(i-1, j, grid);
        int leftScore = solve(i, j-1, grid);
        int diagScore = solve(i-1, j-1, grid);

        int num = 0;
        if(isdigit(grid[i][j])) num = grid[i][j]-'0';

        int maxiScore = max({upScore, leftScore, diagScore});
        if(maxiScore == INT_MIN) return dp1[i][j] = maxiScore; // no path exists
        return dp1[i][j] = num + maxiScore;
    }

    int paths(int i, int j, vector<string>& grid, int sum, int maxScore){
        
        if(i < 0 || j < 0 || grid[i][j] == 'X') return 0;
        if(i == 0 && j == 0 ){

            if(sum == maxScore) return 1;
            return 0;
        }

        if(dp2[i][j][sum] != -1) return dp2[i][j][sum];

        int score = 0;
        if(isdigit(grid[i][j])) score = grid[i][j]-'0';

        int total = 0;
        total = (total + (paths(i-1, j, grid, sum+score, maxScore)%MOD)%MOD);
        total = (total + (paths(i, j-1, grid, sum+score, maxScore)%MOD)%MOD); 
        total = (total + (paths(i-1, j-1, grid, sum+score, maxScore)%MOD)%MOD);

        return dp2[i][j][sum] = total;
    } 

    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        n = board.size();

        memset(dp1, -1, sizeof(dp1));

        int maxScore = solve(n-1, n-1, board);
        if(maxScore < 0) return {0, 0};

        dp2.resize(101, vector<vector<int>>(101, vector<int>(maxScore+1, -1)));
        
        int num_paths = (paths(n-1, n-1, board, 0, maxScore))%MOD;

        return {maxScore, num_paths};
    }
};
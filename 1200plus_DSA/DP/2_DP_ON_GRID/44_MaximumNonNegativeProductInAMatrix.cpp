class Solution {
public:
    int m, n;
    vector<vector<pair<long long, long long>>> dp;
    const long long MOD = 1000000007;

    pair<long long, long long> solve(int i, int j, vector<vector<int>>& grid) {
        if (i >= m || j >= n) return {LLONG_MIN, LLONG_MAX}; // Invalid case

        if (i == m - 1 && j == n - 1) return {grid[i][j], grid[i][j]}; // Base case

        if (dp[i][j].first != LLONG_MIN) return dp[i][j]; // Memoized result

        auto right_move = solve(i, j + 1, grid);
        auto down_move = solve(i + 1, j, grid);

        long long maxi = LLONG_MIN, mini = LLONG_MAX;

        // Update from right move
        if (right_move.first != LLONG_MIN) {
            maxi = max({maxi, right_move.first * grid[i][j], right_move.second * grid[i][j]});
            mini = min({mini, right_move.first * grid[i][j], right_move.second * grid[i][j]});
        }

        // Update from down move
        if (down_move.first != LLONG_MIN) {
            maxi = max({maxi, down_move.first * grid[i][j], down_move.second * grid[i][j]});
            mini = min({mini, down_move.first * grid[i][j], down_move.second * grid[i][j]});
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MAX}));

        auto ans = solve(0, 0, grid);

        long long res = ans.first;
        if (res < 0) return -1;

        return res % MOD;
    }
};

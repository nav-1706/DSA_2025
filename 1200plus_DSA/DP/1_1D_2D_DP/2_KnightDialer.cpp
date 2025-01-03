class Solution {
public:

    vector<vector<int>>dir{{-2 ,1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}};
    unordered_map<int, vector<int>>mp;
    long long int MOD = 1000000007; 

    vector<vector<long long int>>dp;

    int solve(int curr, int n){

        if(n == 1) return 1;

        if(dp[curr][n] != -1) return dp[curr][n];

        int ways = 0;
        for(auto neighbour: mp[curr]){

            ways = (ways + (solve(neighbour, n-1))%MOD)%MOD;
        }

        return dp[curr][n] = ways;
    }

    int knightDialer(int n) {

        mp[0] = {4,6};
        mp[1] = {6,8};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4] = {3,9,0};
        mp[5] = {};
        mp[6] = {1,7,0};
        mp[7] = {6,2};
        mp[8] = {1,3};
        mp[9] = {2,4};

        dp.resize(10, vector<long long int>(n+1, -1));

        long long int total = 0;
        for(int i=0; i<=9; i++){

            total = (total + solve(i, n))%MOD;
        }

        return total;
    }
};
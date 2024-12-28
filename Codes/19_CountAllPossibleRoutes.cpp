class Solution {
public:

    vector<vector<int>>dp;

    int MOD = 1000000007;

    int solve(int curr, int end, int fuel, vector<int>&locations){

        if(fuel == 0 && curr == end) return 1;
        if(fuel == 0 && curr != end) return 0;

        if(dp[curr][fuel] != -1) return dp[curr][fuel];

        // if fuel > 0 OR curr != end
        int ways = 0; // fuel > 0 && curr != end
        if(curr == end) ways = 1; // end par pahuch jaaye, no matter ki fuel bacha hai, ek path count hoga --> fuel > 0 and curr == end

        for(int k=0; k<locations.size(); k++){

            if(k == curr) continue;

            if(fuel >= abs(locations[curr]-locations[k])){
                
                int fuelCost = abs(locations[curr]-locations[k]);
                ways = (ways + (solve(k, end, fuel-fuelCost, locations))%MOD)%MOD;
            }
        }

        return dp[curr][fuel] = ways;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        
        dp.resize(locations.size()+1, vector<int>(fuel+1, -1));

        return solve(start, finish, fuel, locations);
    }
};
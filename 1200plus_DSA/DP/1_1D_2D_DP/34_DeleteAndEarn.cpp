class Solution {
public:

    unordered_map<int, int>mp;
    vector<int>dp;

    int solve(int i, vector<int>&v){

        if(i >= v.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int not_taken = solve(i+1, v);

        int taken = v[i]*mp[v[i]];
        if(i+1 < v.size() && v[i+1] != v[i]+1) taken += solve(i+1, v);
        else taken += solve(i+2, v);

        return dp[i] = max(taken, not_taken);
    }

    int deleteAndEarn(vector<int>& nums) {


        for(int i=0; i<nums.size(); i++){

            mp[nums[i]]++;
        }

        vector<int>v; // uniques elements
        for(auto p: mp) v.push_back(p.first);
        sort(v.begin(), v.end());
        int n = v.size();

        if(v.size() == 1) return v[0]*mp[v[0]];

        dp.resize(n+1, -1);

        return solve(0, v);
    }
};
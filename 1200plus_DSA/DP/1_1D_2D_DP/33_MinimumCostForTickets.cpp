class Solution {
public:

    vector<int>dp;

    int solve(int i, vector<int>&days, vector<int>&costs){

        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int after_7th_day = days[i] + 7; // 7 day ka pass liya to kis din travel karega
        int after_30th_day = days[i] + 30;

        int p = i;
        while( p < days.size() && days[p] < after_7th_day) p++;

        int q = i;
        while( q < days.size() && days[q] < after_30th_day) q++;

        return dp[i] = min(costs[0] + solve(i+1, days, costs), min(costs[1]+solve(p, days, costs), costs[2]+solve(q, days, costs)));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        dp.resize(days.size()+1, -1);
        return solve(0, days, costs);

    }
};
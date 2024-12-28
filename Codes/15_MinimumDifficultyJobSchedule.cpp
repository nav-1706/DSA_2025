class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, vector<int>&job, int d){

        if(job.size() - i < d) return -1;

        if(d == 1){
            
            int maxi = INT_MIN;
            for(int k=i; k<job.size(); k++) maxi = max(maxi, job[k]);
            return maxi;
        }

        if(dp[i][d] != -2) return dp[i][d];

        int n = job.size();
        int mini = INT_MAX; // to return minimum answer
        int maxi = INT_MIN; // to track maximum element int subarray

        for(int k = i; k <= n-d; k++){

            maxi = max(maxi, job[k]);
            mini = min(mini, maxi + solve(k+1, job, d-1));
        }

        return dp[i][d] = mini;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        dp.resize(n+1, vector<int>(d+1, -2));

        if(n < d) return -1;

        return solve(0, jobDifficulty, d);
    }
};
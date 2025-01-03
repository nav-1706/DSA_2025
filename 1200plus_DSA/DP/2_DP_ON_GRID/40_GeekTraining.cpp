class Solution {
  public:
    
    vector<vector<int>>dp;
    
    int solve(int i, int prev_acti, vector<vector<int>>& arr, int n){ // n -->days (n-1) index
        
        
        if(i == n) return 0;
        
        if(dp[i][prev_acti] != -1) return dp[i][prev_acti];
        
        int maxi = INT_MIN;
        
        for(int j=0; j<3; j++){
            
            if(j == prev_acti) continue;
            maxi = max(maxi, arr[i][j] + solve(i+1, j, arr, n));
        }
        
        return dp[i][prev_acti] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        
        dp.resize(n+1, vector<int>(4, -1));
        return solve(0, 3, arr, n); // intitally no prev_activity
    }
};
class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, string &ring, int j, string &key){ // i --> itterate on 'ring', j itterate on 'key'

        if(j == key.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(ring[i] == key[j]){    // is step se character spell ka +1 step count hoga, then key ka next element ko search ke liye call lag jaaega
            return dp[i][j] = 1 + solve(i, ring, j+1, key);
        }

        int mini = INT_MAX;
        int n = ring.length();

        /* We are checking both side of ring, wrt 'i', to check multiple occurances on both side(i.e one on lest and one on right and so on...)

        // for(int k = i+1; k<ring.size(); k++){

        //     if(ring[k] == key[j]){  // forward search --> Anticlock-wise

        //         int dist = min(k-i, n-k);
        //         mini = min(mini, dist + solve(k, ring, j, key));
        //     }
        // }

        // for(int k = i-1; k>=0; k--){ // backward search --> Clock-wise
 
        //     if(ring[k] == key[j]){

        //         int dist = min(i-k, n-i);
        //         mini = min(mini, dist + solve(k, ring, j, key));
        //     }
        // }
        */

        for(int k=0; k<n; k++){

            if(ring[k] == key[j]){

                int dist = min(abs(k-i), n - abs(k-i));

                mini = min(mini, dist+solve(k, ring, j, key));
            }
        }

        return dp[i][j] = mini;
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length();
        int m = key.size();

        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(0, ring, 0, key);
    }
};
class Solution {
public:

    int m;
    int n;
    vector<vector<int>>apple;
    int dp[55][55][15];

    long long int MOD = 1000000007;

    int solve(int i, int j, int k){

        if(apple[i][j] < k) return 0;

        if(k == 1) return apple[i][j] >= 1;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ways = 0;

        // Horizontal cuts

        for(int h = i+1; h<m; h++){

            int lower_slice_count = apple[h][j];
            int upper_slice_count = apple[i][j] - lower_slice_count;

            if(upper_slice_count >= 1 && lower_slice_count >= k-1){

                ways = (ways + (solve(h, j, k-1))%MOD)%MOD;
            }
        }

        // Vertical cuts

        for(int v = j+1; v<n; v++){

            int right_slice_count = apple[i][v];
            int left_slice_count = apple[i][j] - right_slice_count;

            if(left_slice_count >= 1 && right_slice_count >= k-1){

                ways = (ways + solve(i, v, k-1)%MOD)%MOD;
            }
        }

        return dp[i][j][k] = ways;
    }

    int ways(vector<string>& pizza, int k) {
        
        m = pizza.size(); // rows
        n = pizza[0].length(); // cols

        // make apple_count array

        apple.resize(m+1, vector<int>(n+1, 0));

        // int apple[55][55];
        // memset(apple, 0, sizeof(apple)); 

        // apple[i][j] = number of apple inn pizza from [i][j]-----------[m-1][n-1] 2-d grid

        for(int i = m-1; i>=0; i--){

            for(int j = n-1; j>=0; j--){

                apple[i][j] = apple[i][j+1];

                for(int l = i; l<m; l++){
                    
                    if(pizza[l][j] == 'A') apple[i][j]++;
                    
                }
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, k);
    }
};
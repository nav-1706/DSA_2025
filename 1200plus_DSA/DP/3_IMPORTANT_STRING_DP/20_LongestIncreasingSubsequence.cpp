/* ***************** METHOD-1: RECURSION + DP **********************************************
-------------------------------------------------------------------------------------------*/

class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, int prevIdx, vector<int>nums){

        if(i == nums.size()) return 0;

        if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1]; // +1 offset for prevIdx = -1

        int res = INT_MIN;

        if(prevIdx == -1 || nums[i] > nums[prevIdx]){

            res = max(res, 1 + solve(i+1, i, nums));
        }

        res = max(res, solve(i+1, prevIdx, nums));

        return dp[i][prevIdx+1] = res;
    }

    int lengthOfLIS(vector<int>& nums) {
        
        dp.resize(nums.size()+2, vector<int>(nums.size()+2, -1));
        return solve(0, -1, nums);
    }
};

/* **************** METHOD 2: BOTTOM-UP + PRINTING **************************************
-----------------------------------------------------------------------------------------*/

// https://youtu.be/h9rm4N8XbL0?si=E3PZBi6PJN0K7so8

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // state defination, dp[i] --> exactly i-th index par khatam hone wale LIS ki length kya hai;

        int n = nums.size();

        vector<int>dp(n, 1);
        int maxlen = 1;

        // ** printing **

        vector<int>prevIdx(n, -1);
        int lastIndex = 0;

        for(int i=0; i<n; i++){

            for(int j=0; j < i; j++){

                if(nums[i] > nums[j] ){

                    if(dp[j] + 1 > dp[i]){
                        
                        dp[i] = dp[j]+1;
                        prevIdx[i] = j;
                    }

                }
            }

            if(dp[i] > maxlen){

                lastIndex = i;
                maxlen = dp[i];
            }
        }

        for(int i=0; i<prevIdx.size(); i++) cout<<prevIdx[i]<<" ";
        cout<<endl;
        cout<<lastIndex;
        cout<<endl;

        vector<int> lis;
        for (int i = lastIndex; i != -1; i = prevIdx[i]) {
            lis.push_back(nums[i]);
        }
        reverse(lis.begin(), lis.end());

        for (int num : lis) {
            cout << num << " ";
        }
        return maxlen;
    }
};

/* ************************** METHOD 3: LAZY SORTING ****************************************
---------------------------------------------------------------------------------------------*/

class Solution {
public:

    // SOLVED USING: PATIENCE SORTING
    // https://youtu.be/dWmh3O8uX8A?si=ZFZOMQCYfxcgVASi
    // lower bound --> element equal or just greater than the given number --> TC = O(log(n))

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>sorted;

        for(int i=0; i<n; i++){
            auto it = lower_bound(begin(sorted), end(sorted), nums[i]); // returns iterator, do *it to get element

            if(it == end(sorted)){ // nahi mila koi aisa element
                
                sorted.push_back(nums[i]);
            }

            else{ // found
                *it = nums[i]; // replaced with nums[i];
            } 
        }

        return sorted.size();
    }
};
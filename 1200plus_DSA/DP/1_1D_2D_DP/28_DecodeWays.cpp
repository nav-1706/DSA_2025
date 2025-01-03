class Solution {
public:

    vector<int>dp;

    int solve(string &s, int i){

        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int ways = 0;
        if(s[i] != '0') ways += solve(s, i+1);

        if(i+1 < s.size()){
            string num = "";
            num.push_back(s[i]);
            num.push_back(s[i+1]);
    
            int int_num = stoi(num);

            if(int_num <= 26){
                ways += solve(s, i+2);
            }
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;

        dp.resize(s.size()+1, -1);
        // for(int i=1; i<s.size(); i++){
            
        //     if(s[i] == '0'){
        //         if(s[i] != '1' && s[i] != '2') return 0;
        //     }
        // }

        return solve(s, 0);
    }
};
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string res = "";
        int count = 0;

        for(int i=s.length()-1; i>=0; i--){
            
            if(s[i] == '-') continue;

            if(isdigit(s[i])){
                
                // res = s[i] + res;
                res.push_back(s[i]);
                count++;
            }

            else if(islower(s[i])){
                
                char capi = char(s[i]-32);
                res.push_back(capi);
                count++;
            }

            else {
                res.push_back(s[i]);
                count++;
            }

            if(count == k){

                res.push_back('-');
                count = 0;
            }

        }

        cout<<res<<endl;
        cout<<s.length();
        
        if (!res.empty() && res.back() == '-') {
            res.pop_back();
        }

        // Reverse the result to correct the order
        reverse(res.begin(), res.end());
        return res;
    }
};
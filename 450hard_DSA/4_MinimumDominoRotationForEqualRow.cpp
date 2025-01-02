class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        

        unordered_map<int,vector<int>>mp; // <dice_number(0-6), vector<count of i in top, in bottom, both common>
        int n = tops.size();

        for(int i=1; i<=6; i++){

            mp[i] = vector<int>(3, 0);
        }

        for(int i=0; i<tops.size(); i++){

            int top_ele = tops[i];
            int bottom_ele = bottoms[i];

            if(top_ele != bottom_ele){

                mp[top_ele][0]++;
                mp[bottom_ele][1]++;
            }

            else mp[top_ele][2]++;
        }

        int mini = INT_MAX;

        for(auto entry: mp){

            if(entry.second[0] + entry.second[1] + entry.second[2] == n){

                mini = min({mini, entry.second[0] , entry.second[1]});
            }
        }

        if(mini == INT_MAX) return -1;
        return mini;
    }
};
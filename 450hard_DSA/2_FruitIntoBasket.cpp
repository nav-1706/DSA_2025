// https://youtu.be/e3bs0uA1NhQ?si=ZgZ3Jt8OuJzlXtUv

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int>mp;
        int max_collected = 0;
        int r = 0;
        int l = 0;
        int k = 2;

        while(r < fruits.size()){

            mp[fruits[r]]++;

            while(mp.size() > k){ // not-possible

                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }

            // now map has two elements --> that is two distinct elements

            max_collected = max(max_collected, r-l+1);

            r++;
        }

        return max_collected;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int maxProfit = 0;
        int minimumPrice = prices[0];

        for(int i=1; i<n; i++){

            maxProfit = max(maxProfit, prices[i]-minimumPrice);
            minimumPrice = min(minimumPrice, prices[i]);
        }

        return maxProfit;
    }
};
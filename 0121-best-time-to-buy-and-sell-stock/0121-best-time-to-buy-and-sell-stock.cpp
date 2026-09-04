class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minElementInRange = prices[0];
        int maxProfit = 0;
        for(int i = 1; i<n;i++){
            maxProfit = max(prices[i] - minElementInRange,maxProfit);
            minElementInRange = min(minElementInRange,prices[i]);
        }
        return maxProfit;
        
    


        
    }
};
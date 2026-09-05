class Solution {
public:

    // Memoization
    // int getMaxProfit(vector<int> &prices,int i, int canBuy,vector<vector<int>> &dp){
    
    //     if(i==prices.size()){
    //         return dp[i][canBuy] = 0;
    //     }

    //     if(dp[i][canBuy] != -1){
    //         return dp[i][canBuy];
    //     }

    //     if(canBuy){
    //         return dp[i][canBuy] = max(-prices[i]+getMaxProfit(prices,i+1,0,dp),getMaxProfit(prices,i+1,1,dp));
    //     }
    //     else{
    //         return dp[i][canBuy] = max(prices[i]+getMaxProfit(prices,i+1,1,dp),getMaxProfit(prices,i+1,0,dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // dp[n][0] = 0;
        // dp[n][1] = 0;
        
        int prevToSell = 0;//space optmization
        int prevToBuy = 0;

        for(int i = n-1;i>=0;i--){
            int currToBuy = max(-prices[i]+prevToSell,prevToBuy);
            int currToSell = max(prices[i] + prevToBuy,prevToSell);
            prevToBuy = currToBuy;
            prevToSell = currToSell;
        }
        return prevToBuy;

        // return dp[0][1];
    }
};
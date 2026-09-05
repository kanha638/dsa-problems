class Solution {
public:

    int getMaxProfit(vector<int> &prices,int i, int canBuy,vector<vector<int>> &dp){
    
        if(i==prices.size()){
            return dp[i][canBuy] = 0;
        }

        if(dp[i][canBuy] != -1){
            return dp[i][canBuy];
        }

        if(canBuy){
            return dp[i][canBuy] = max(-prices[i]+getMaxProfit(prices,i+1,0,dp),getMaxProfit(prices,i+1,1,dp));
        }
        else{
            return dp[i][canBuy] = max(prices[i]+getMaxProfit(prices,i+1,1,dp),getMaxProfit(prices,i+1,0,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return getMaxProfit(prices,0,1,dp);

    }
};
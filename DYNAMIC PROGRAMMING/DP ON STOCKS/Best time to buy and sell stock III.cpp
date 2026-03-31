//memoization
class Solution {
public:
    int func(int i,int cap,int buy,int n,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(cap==0){
            return 0;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][buy][cap] != -1){
            return dp[i][buy][cap];
        }
        int profit= 0;

        if(buy==1){
            profit=max(-prices[i]+func(i+1,cap,0,n,prices,dp),
                        0+func(i+1,cap,1,n,prices,dp));
        }else{
             profit=max(prices[i]+func(i+1,cap-1,1,n,prices,dp),
                        0+func(i+1,cap,0,n,prices,dp));
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,
                vector<vector<int>> (2,vector<int> (3,-1)));
        return func(0,2,1,n,prices,dp);
    }
};
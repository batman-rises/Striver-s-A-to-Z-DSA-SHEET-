class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minm=prices[0];
        int maxm=INT_MIN;
        for(int i=0;i<prices.size();i++){
            int proftPerTransaction=prices[i]-minm;
            maxm=max(maxm,proftPerTransaction);
            minm=min(minm,prices[i]);
        }
        return maxm;
    }
};
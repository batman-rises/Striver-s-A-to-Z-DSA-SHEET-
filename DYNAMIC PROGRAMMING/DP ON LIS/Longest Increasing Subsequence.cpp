class Solution {
public:
    int func(int i,int prev,vector<vector<int>> &dp,vector<int>& a,int n){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        //not take
        int len=0+func(i+1,prev,dp,a,n);
        if(prev==-1 || a[prev]<a[i]){
            len=max(len,1+func(i+1,i,dp,a,n));
        }
        return dp[i][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return func(0,-1,dp,a,n);
    }
};
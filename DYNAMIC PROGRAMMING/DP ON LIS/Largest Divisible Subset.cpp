class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi=1;
        int last=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(a[i]%a[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int>temp;
        temp.push_back(a[last]);
        while(last != hash[last]){
            last=hash[last];
            temp.push_back(a[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
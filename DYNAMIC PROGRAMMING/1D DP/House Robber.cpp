class Solution
{
public:
    int robLinear(vector<int> &arr, int i, vector<int> &dp)
    {
        if (i == 0)
            return arr[0];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = arr[i] + robLinear(arr, i - 2, dp);
        int notPick = robLinear(arr, i - 1, dp);

        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robLinear(nums, n - 1, dp);
    }
};


//tabulation
class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n+1,0);
        dp[0]=a[0];
        for(int i=1;i<n;i++){
            int take=a[i];
            if(i>1)
                take+=notTakedp[i-2];
            int =0+dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
};
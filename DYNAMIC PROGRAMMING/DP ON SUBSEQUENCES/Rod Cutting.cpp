class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int len = 0; len <= n; len++)
        {
            dp[0][len] = len * price[0]; // only first piece (length 1) can be used
        }

        for (int i = 1; i < n; i++)
        {
            for (int len = 0; len <= n; len++)
            {
                int notTake = dp[i - 1][len];
                int take = INT_MIN;
                int rodLength = i + 1;
                if (rodLength <= len)
                {
                    take = price[i] + dp[i][len - rodLength];
                }
                dp[i][len] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};

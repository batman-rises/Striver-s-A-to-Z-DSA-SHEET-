// User function Template for C++

class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int W)
    {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int w = 0; w <= W; w++)
        {
            dp[0][w] = (w / wt[0]) * val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                int notTake = 0 + dp[i - 1][w];
                int take = INT_MIN;
                if (wt[i] <= w)
                {
                    take = val[i] + dp[i][w - wt[i]];
                }
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};
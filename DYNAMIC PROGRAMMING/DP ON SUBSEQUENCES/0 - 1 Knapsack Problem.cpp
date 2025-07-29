class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        // base case
        for (int i = wt[0]; i <= W; i++)
        {
            dp[0][i] = val[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                int notTake = 0 + dp[i - 1][w];
                int take = -1e9;
                if (wt[i] <= w)
                {
                    take = val[i] + dp[i - 1][w - wt[i]];
                }
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n - 1][W];
    }
};
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &a)
    {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: first row
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = a[0][j];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int up = a[i][j] + dp[i - 1][j];

                int leftDiag = a[i][j] + (j > 0 ? dp[i - 1][j - 1] : 1e9);
                int rightDiag = a[i][j] + (j < m - 1 ? dp[i - 1][j + 1] : 1e9);

                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }

        // Find the minimum value in the last row
        int mini = 1e9;
        for (int j = 0; j < m; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};

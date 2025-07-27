class Solution
{
public:
    int minimumDifference(vector<int> &a)
    {
        int n = a.size();
        int total = accumulate(a.begin(), a.end(), 0);
        int k = total;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base case
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (a[0] <= k)
            dp[0][a[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (target >= a[i])
                    take = dp[i - 1][target - a[i]];
                dp[i][target] = take || notTake;
            }
        }

        int mini = INT_MAX;
        for (int s1 = 0; s1 <= total / 2; s1++)
        {
            if (dp[n - 1][s1])
            {
                int s2 = total - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }

        return mini;
    }
};
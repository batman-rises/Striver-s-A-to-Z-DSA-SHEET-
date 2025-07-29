class Solution
{
public:
    int mod = 1e9 + 7;

    int f(vector<int> &arr, int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // base case
        if (arr[0] == 0)
        {
            dp[0][0] = 2; // two options: pick or not pick
        }
        else
        {
            dp[0][0] = 1; // only one option: not pick
        }

        if (arr[0] != 0 && arr[0] <= sum)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= sum; target++)
            {
                int notpick = dp[i - 1][target];
                int pick = 0;
                if (arr[i] <= target)
                    pick = dp[i - 1][target - arr[i]];
                dp[i][target] = (pick + notpick) % mod;
            }
        }

        return dp[n - 1][sum];
    }

    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        if ((total - d) < 0 || (total - d) % 2 != 0)
            return 0;

        int subsetSum = (total - d) / 2;
        return f(arr, n, subsetSum);
    }
};

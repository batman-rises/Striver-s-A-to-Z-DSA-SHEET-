class Solution
{
public:
    int change(int val, vector<int> &coins)
    {
        int n = coins.size();
        // vector<vector<long long>> dp(n, vector<long long>(val + 1, 0));
        vector<int> prev(val + 1, 0), cur(val + 1, 0);
        // Base case
        for (int t = 0; t <= val; t++)
        {
            if (t % coins[0] == 0)
                prev[t] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= val; t++)
            {
                long long notTake = prev[t];
                long long take = 0;
                if (coins[i] <= t)
                {
                    take = cur[t - coins[i]];
                }
                cur[t] = take + notTake;
            }
            prev = cur;
        }

        return prev[val];
    }
};

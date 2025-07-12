class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int prev = 0;
        int prev2 = 0;
        int cur = 0;
        int n = stones.size();
        for (int i = 1; i < n; i++)
        {
            int fs = prev + abs(stones[i] - stones[i - 1]);
            int ss = INT_MAX;
            ss = prev2 + abs(stones[i] - stones[i - 2]);

            cur = min(fs, ss);
            prev2 = prev;
            prev = cur;
        }
        return cur == 0 ? false : true;
    }
};

int maxJump(vector<int> &stones)
{
    int n = stones.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(a[i] - a[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}
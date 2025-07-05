// recursion
int func(int n)
{
    if (n <= 1)
        return n;

    return func(n - 1) + func(n - 2);
}

// memoization
int func(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = func(n - 1, dp) + func(n - 2, dp);
}
// tabulation
int func(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// further space optimization
int func(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
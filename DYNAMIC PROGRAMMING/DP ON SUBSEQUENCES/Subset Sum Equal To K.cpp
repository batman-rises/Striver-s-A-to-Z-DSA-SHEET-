#include <bits/stdc++.h>
bool f(vector<int> &arr, int i, int k, vector<vector<int>> &dp)
{
    // base cases
    if (k == 0)
        return true;
    if (i == 0)
        return arr[0] == k;
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    bool notPick = f(arr, i - 1, k, dp);
    bool pick = false;
    if (k >= arr[i])
    {
        pick = f(arr, i - 1, k - arr[i], dp);
    }
    return dp[i][k] = pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return f(arr, n - 1, k, dp);
}
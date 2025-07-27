int mod = 1e9 + 7;

int f(vector<int> &arr, int k, int i, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (i == 0)
        return arr[0] == k;
    // if (i == 0) {
    // if (k == 0 && arr[0] != 0) return 1; // only empty subset
    // if (k == 0 && arr[0] == 0) return 2; // take or not take
    // if (arr[0] == k) return 1;           // take this single element
    // return 0;
    // }
    if (dp[i][k] != -1)
        return dp[i][k];
    int notTake = f(arr, k, i - 1, dp);
    int take = 0;
    if (arr[i] <= k)
        take = f(arr, k - arr[i], i - 1, dp);
    return dp[i][k] = (take + notTake) % mod;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return f(arr, k, n - 1, dp);
}

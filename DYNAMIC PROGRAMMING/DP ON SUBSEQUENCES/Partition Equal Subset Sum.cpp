class Solution
{
public:
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
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2)
            return false;
        int k = total / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(nums, n - 1, k, dp);
    }
};
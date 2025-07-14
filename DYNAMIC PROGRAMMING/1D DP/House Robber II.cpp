class Solution
{
public:
    int robLinear(vector<int> &arr, int i, vector<int> &dp)
    {
        if (i == 0)
            return arr[0];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = arr[i] + robLinear(arr, i - 2, dp);
        int notPick = robLinear(arr, i - 1, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0]; // only one house

        // Exclude the first house
        vector<int> excludeFirst(nums.begin() + 1, nums.end());

        // Exclude the last house
        vector<int> excludeLast(nums.begin(), nums.end() - 1);
        vector<int> dp(n, -1);
        int p1 = robLinear(excludeFirst, n - 2, dp); // n - 2 because size is now n - 1
        vector<int> dp2(n, -1);
        int p2 = robLinear(excludeLast, n - 2, dp2);

        return max(p1, p2);
    }
};

class Solution
{
public:
    int findWays(vector<int> &nums, int d)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(d + 1, 0));
        if (nums[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }
        if (nums[0] != 0 && nums[0] <= d)
        {
            dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= d; target++)
            {
                int nottake = dp[i - 1][target];
                int take = 0;
                if (nums[i] <= target)
                {
                    take = dp[i - 1][target - nums[i]];
                }
                dp[i][target] = take + nottake;
            }
        }
        return dp[n - 1][d];
    }
    int findTargetSumWays(vector<int> &nums, int d)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total - d < 0 || (total - d) % 2)
            return 0;

        return findWays(nums, (total - d) / 2);
    }
};
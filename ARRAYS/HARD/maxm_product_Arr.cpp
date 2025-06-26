class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int suf = 1, pre = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;

            suf *= nums[n - i - 1];
            pre *= nums[i];

            ans = max(ans, max(suf, pre));
        }
        return ans;
    }
};
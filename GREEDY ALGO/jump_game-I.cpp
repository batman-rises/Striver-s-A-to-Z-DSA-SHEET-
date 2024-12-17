bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxInd = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxInd >= n - 1)
            return true;

        if (maxInd < i)
            return false;

        maxInd = max(maxInd, nums[i] + i);
    }
    return maxInd;
}
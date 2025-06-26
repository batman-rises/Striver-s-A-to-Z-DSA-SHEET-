class Solution
{
public:
    int maxScore(vector<int> &arr, int k)
    {
        int lsum = 0, rsum = 0, maxsum = 0, r;
        for (int i = 0; i < k; i++)
        {
            lsum += arr[i];
        }
        maxsum = lsum;
        r = arr.size() - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= arr[i];
            rsum += arr[r];
            r--;
            maxsum = max(maxsum, lsum + rsum);
        }
        return maxsum;
    }
};
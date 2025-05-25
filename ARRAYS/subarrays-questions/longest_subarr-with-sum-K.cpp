int longestSubarray(vector<int> &arr, int k)
{
    // code here
    unordered_map<long long, int> mp;
    int len = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            len = max(len, i + 1);
        }
        int rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            len = max(len, i - mp[rem]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return len;
}
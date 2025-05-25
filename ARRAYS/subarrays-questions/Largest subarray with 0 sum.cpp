class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> mp;
        int sum = 0, len = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                len = max(len, i + 1);
            }
            if (mp.find(sum) != mp.end())
            {
                len = max(len, i - mp[sum]);
            }
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return len;
    }
};
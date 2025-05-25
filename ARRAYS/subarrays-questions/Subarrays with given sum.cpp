class Solution
{
public:
    int subArraySum(vector<int> &arr, int k)
    {
        // code here.
        unordered_map<long long, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            int rem = sum - k;
            cnt += mp[rem];
            mp[sum] += 1;
        }
        return cnt;
    }
};
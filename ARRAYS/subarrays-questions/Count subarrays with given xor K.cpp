class Solution
{
public:
    int subarraysWithXorK(vector<int> &arr, int k)
    {
        map<int, int> mp;
        mp[0] = 1;
        int xr = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            xr ^= arr[i];
            int x = xr ^ k;
            cnt += mp[x];
            mp[xr] += 1;
        }
        return cnt;
    }
};
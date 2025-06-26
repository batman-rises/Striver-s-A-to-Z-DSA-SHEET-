class Solution
{
public:
    int func(vector<int> &s, int k)
    {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mp;
        int n = s.size();
        while (r < n)
        {
            mp[s[r]]++;
            while (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);

                l++;
            }
            if (mp.size() <= k)
            {
                cnt += (r - l + 1);
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int> &s, int k)
    {
        return func(s, k) - func(s, k - 1);
    }
};
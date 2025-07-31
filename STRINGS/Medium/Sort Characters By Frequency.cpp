class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        // hashing
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> h;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            h.push({i->second, i->first});
        }
        string ans = "";
        int j = 0;
        while (!h.empty())
        {
            for (int i = 0; i < h.top().first; i++)
            {
                ans += h.top().second;
            }
            h.pop();
        }
        return ans;
    }
};
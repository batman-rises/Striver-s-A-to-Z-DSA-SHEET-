class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            h.push({i->second, -i->first});

            // if(h.size()>k)h.pop();
        }
        vector<int> ans;
        while (!h.empty())
        {
            for (int i = 0; i < h.top().first; i++)
                ans.push_back(-h.top().second);
            h.pop();
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
        for (int i = 0; i < n; i++)
        {
            h.push({arr[i], i});
        }
        int rank = 0;
        int prevVal = INT_MIN;
        vector<int> res(n);
        while (!h.empty())
        {
            auto [val, i] = h.top();
            h.pop();

            if (val != prevVal)
            {
                ++rank;
                prevVal = val;
            }
            res[i] = rank;
        }
        return res;
    }
};
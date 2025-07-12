class Solution
{
public:
    int maxJump(vector<int> &stones)
    {
        int prev = 0;
        int prev2 = 0;
        int cur = 0;
        int n = stones.size();
        for (int i = 1; i < n; i++)
        {
            int fs = prev + abs(stones[i] - stones[i - 1]);
            int ss = INT_MAX;
            ss = prev2 + abs(stones[i] - stones[i - 2]);

            cur = min(fs, ss);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};
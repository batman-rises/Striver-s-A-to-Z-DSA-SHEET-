class Solution
{
public:
    bool possible(vector<int> &bloomDay, int day, int m, int k)
    {
        int cnt = 0;
        int n = bloomDay.size();
        int noOfBq = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= day)
            {
                cnt++;
            }
            else
            {
                noOfBq += (cnt / k);
                cnt = 0;
            }
        }
        noOfBq += (cnt / k);
        return (noOfBq >= m) ? true : false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if ((long long)(m * k) > bloomDay.size())
            return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        for (int i = mini; i <= maxi; i++)
        {
            if (possible(bloomDay, i, m, k))
                return i;
        }
        return -1;
    }
};
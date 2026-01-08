class Solution
{
public:
    int func(vector<int> &a, int maxi)
    {
        int k = 1;
        int workPerPainter = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (workPerPainter + a[i] <= maxi)
            {
                workPerPainter += a[i];
            }
            else
            {
                k++;
                workPerPainter = a[i];
            }
        }
        return k;
    }
    int minTime(vector<int> &a, int k)
    {
        // code here
        int l = *max_element(a.begin(), a.end());
        int h = accumulate(a.begin(), a.end(), 0);
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int painters = func(a, mid);
            if (painters > k)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return l;
    }
};
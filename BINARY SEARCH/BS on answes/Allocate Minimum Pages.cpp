class Solution
{
public:
    int func(vector<int> &a, int maxi)
    {
        int k = 1;
        int pagesPerStudent = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (pagesPerStudent + a[i] <= maxi)
            {
                pagesPerStudent += a[i];
            }
            else
            {
                k++;
                pagesPerStudent = a[i];
            }
        }
        return k;
    }
    int findPages(vector<int> &a, int k)
    {
        // code here
        if (k > a.size())
            return -1;
        int l = *max_element(a.begin(), a.end());
        int h = accumulate(a.begin(), a.end(), 0);
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int studs = func(a, mid);
            if (studs > k)
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
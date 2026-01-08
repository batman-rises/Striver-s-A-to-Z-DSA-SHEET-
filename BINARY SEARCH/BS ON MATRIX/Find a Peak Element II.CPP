class Solution
{
public:
    int func(vector<vector<int>> &a, int col)
    {
        int m = a.size();
        int ind = -1, maxi = -1;
        for (int i = 0; i < m; i++)
        {
            if (a[i][col] > maxi)
            {
                maxi = a[i][col];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>> &a)
    {
        int m = a.size();
        int n = a[0].size();
        int l = 0, h = n - 1;
        vector<int> res;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int maxi = func(a, mid); // index of row having the maxm element
            int left = (mid - 1 >= 0) ? a[maxi][mid - 1] : -1;
            int right = (mid + 1 < n) ? a[maxi][mid + 1] : -1;
            if (left < a[maxi][mid] && right < a[maxi][mid])
            {
                return {maxi, mid};
            }
            else if (left > a[maxi][mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return {-1, -1};
    }
};
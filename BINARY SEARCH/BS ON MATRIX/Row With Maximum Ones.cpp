class Solution
{
public:
    int lb(vector<int> a, int x)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        int l = 0, h = n - 1;
        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (a[mid] >= x)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>> &a)
    {
        int maxi = 0;

        int m = a.size();
        int n = a[0].size();
        int ind = -1;
        for (int i = 0; i < m; i++)
        {
            int ones = n - lb(a[i], 1);

            if (ones > maxi)
            {
                maxi = ones;
                ind = i;
            }
        }
        return {ind, maxi};
    }
};

// method 2 if rows are sorted

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &a)
    {
        int maxi = -1, ind = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int count = 0;
            for (int x : a[i])
            {
                if (x == 1)
                    count++;
            }
            if (count > maxi)
            {
                maxi = count;
                ind = i;
            }
        }
        return {ind, maxi};
    }
};
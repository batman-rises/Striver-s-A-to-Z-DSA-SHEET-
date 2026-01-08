class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &a, int target)
    {
        int m = a.size();
        int n = a[0].size();
        int l = 0, h = m * n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int row = mid / n;
            int col = mid % n;
            int x = a[row][col];
            if (x == target)
                return true;
            else if (x < target)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
    }
};
class Solution
{
    void func(int i, int k, int sum, int n, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (sum > n || k < 0)
            return;

        if (k == 0)
        {
            if (sum == n)
            {
                ans.push_back(ds);
            }
            return;
        }

        if (i > 9)
            return;

        // pick
        ds.push_back(i);
        func(i + 1, k - 1, sum + i, n, ds, ans);
        // changes
        ds.pop_back();
        // not pick
        func(i + 1, k, sum, n, ds, ans);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        func(1, k, 0, n, ds, ans);
        return ans;
    }
};
void solve(int i, vector<int> &ds, vector<vector<int>> &res, int sum, int k, vector<int> arr, int n)
{
    if (sum > k)
        return;

    if (i == n)
    {
        if (sum == k)
        {
            res.push_back(ds);
        }
        return;
    }
    // pick
    ds.push_back(arr[i]);
    sum += arr[i];
    solve(i + 1, ds, res, sum, k, arr, n);
    // make necessary changes for unpick
    s -= arr[i];
    ds.pop_back();
    // not pick
    solve(i + 1, ds, res, sum, k, arr, n);
}
bool solve(int i, vector<int> &ds, vector<vector<int>> &res, int sum, int k, vector<int> arr, int n)
{
    if (i == n)
    {
        if (sum == k)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            return true;
        }
        return false;
    }
    // pick
    ds.push_back(arr[i]);
    sum += arr[i];
    if (solve(i + 1, ds, res, sum, k, arr, n) == true)
        return true;
    // make necessary changes for unpick
    s -= arr[i];
    ds.pop_back();
    // not pick
    if (solve(i + 1, ds, res, sum, k, arr, n) == true)
        return true;
}
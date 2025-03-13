// int solve(int i, vector<int> &ds, vector<vector<int>> &res, int sum, int k, vector<int> arr, int n)
int solve(int i, int sum, int k, vector<int> arr, int n)
{
    if (sum > k)
        return 0;
    if (i == n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }

    // pick
    // ds.push_back(arr[i]);
    sum += arr[i];
    int l = solve(i + 1, sum, k, arr, n);

    // make necessary changes for unpick
    s -= arr[i];
    // ds.pop_back();

    //  not pick
    int r = solve(i + 1, sum, k, arr, n);
    return (l + r);
}
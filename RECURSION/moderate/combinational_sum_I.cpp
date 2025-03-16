vector<vector<int>> cs(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    func(0, target, arr, ds, ans);
    return ans;
}
void func(int i, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    if (arr.size() == i)
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    // pick
    if (arr[i] <= target)
    {
        ds.push_back(arr[i]);
        func(i, target - arr[i], arr, ds, ans);
        ds.pop_back();
    }
    // not pick
    func(i + 1, target, arr, ds, ans);
}
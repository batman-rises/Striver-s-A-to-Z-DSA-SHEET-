vector<vector<int>> csII(vector<int> arr, int target)
{
    vector<int> ds;
    vector<vector<int>> ans;
    func(0, target, arr, ds, ans);
    return ans;
}
void func(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds) return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        func(i + 1, target - arr[i], arr, ds, ans);
        ds.pop_back();
    }
}
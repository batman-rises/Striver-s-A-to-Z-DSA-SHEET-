int minm(vector<int> &arr, int n)
{
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
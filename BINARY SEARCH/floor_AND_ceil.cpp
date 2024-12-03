int findFloor(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int findCeil(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
pair<int, int> find_floor_and_ceil(const vector<int> &arr, int n, int x)
{
    int floorIndex = findFloor(arr, n, x);
    int ceilIndex = findCeil(arr, n, x);

    int floorValue = (floorIndex != -1) ? arr[floorIndex] : -1;
    int ceilValue = (ceilIndex != -1) ? arr[ceilIndex] : -1;

    return {floorValue, ceilValue};
}
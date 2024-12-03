int first(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int temp = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            temp = mid;
            high = mid - 1;
        }
        else if (arr[mid > x])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return temp;
}
int last(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int temp = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            temp = mid;
            low = mid + 1;
        }
        else if (arr[mid > x])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return temp;
}

int total_occ(vector<int> arr, int n, int x)
{
    int a = first(arr, n, x);
    if (a == -1)
        return -1;
    int b = last(arr, n, x);
    return (b - a + 1);
}
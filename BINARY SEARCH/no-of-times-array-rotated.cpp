// logic is simply just find the index of the minimum value

int func(vector<int> &arr, int n)
{
    int low = 0, high = n - 1;
    int index = -1, ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[mid])
        {
            if (ans > arr[low])
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}
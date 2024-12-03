// WHEN ONLY UNIQUE ELEMENTS

int find(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == x)
            return mid;

        // identifying the sorted half

        if (arr[low] <= arr[mid])
        { // IF LEFT HALF SORTED
            if (arr[low] <= x && x <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        { // IF RIGHT HALF SORTED
            if (arr[mid] <= x && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
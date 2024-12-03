func(arr, low, high, target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return func(arr, low, mid - 1, target);
    else
        return func(arr, mid + 1, high, target);
}
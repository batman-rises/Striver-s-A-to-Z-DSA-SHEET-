// approach 1
func(arr, n, target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int n = arr[i];
        int moreNeeded = target - n;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[n] = i;
    }
    return {-1, -1};
}

// approach 2
func(arr, n, target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int s = arr[left] + arr[right];
        if (s == target)
        {
            return true;
        }
        else if (s < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return false;
}
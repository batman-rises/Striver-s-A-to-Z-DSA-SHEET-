func(arr, n, d)
{
    vector<int> temp;
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    int j = 0;
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[j++];
    }
    return temp;
}
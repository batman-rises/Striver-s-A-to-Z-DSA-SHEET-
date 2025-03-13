func(arr, n)
{
    x = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ arr[i];
    }
    return x;
}
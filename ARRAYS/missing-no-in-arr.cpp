func(arr, n)
{
    int s1 = 0, s2 = 0;
    s1 = n * (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        s2 += arr[i];
    }
    return (s1 - s2);
}
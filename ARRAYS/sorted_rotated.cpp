func(arr, n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1] % n)
            c++;
    }
    if (c == 1)
        return true;
    else
        return false;
}
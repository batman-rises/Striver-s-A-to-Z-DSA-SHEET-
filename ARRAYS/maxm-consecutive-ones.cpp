func(arr, n)
{
    int c = 0, maxi = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            c++;
            maxi = max(maxi, c);
        }
        else
        {
            c = 0;
        }
    }
    return maxi;
}
// MOORE'S VOTING ALGO
func(arr, n)
{
    int cnt = 0, el;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            cnt2++;
    }
    if (cnt2 > (n / 2))
    {
        return el;
    }
    return -1
}
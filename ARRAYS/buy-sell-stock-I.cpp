func(arr, n)
{
    int minm = arr[0];
    int maxm = 0;
    for (int i = 0; i < n; i++)
    {
        int profit = arr[i] - minm;
        int maxProfit = max(maxProfit, profit);
        minm = min(minm, arr[i]);
    }
    return maxProfit;
}
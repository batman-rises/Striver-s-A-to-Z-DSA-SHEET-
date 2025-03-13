func(arr, n, i)
{
    if (i >= (n / 2))
        return;

    swap(arr[i], arr[n - i - 1]);
    func(arr, n, i + 1);
}
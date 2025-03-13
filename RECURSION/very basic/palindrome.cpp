bool func(arr, n, i)
{
    if (i >= (n / 2))
        return true;

    if (arr[i] != arr[n - i - 1])
        return false;

    func(arr, n, i + 1);
}
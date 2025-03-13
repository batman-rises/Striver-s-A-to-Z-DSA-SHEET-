func(n)
{
    if (n == 0)
        return;

    cout << n << endl;
    func(n - 1);
}

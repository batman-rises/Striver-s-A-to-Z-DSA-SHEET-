int solve(int n)
{
    if (n < 10)
        return 1;

    return 1 + solve(n / 10);
}
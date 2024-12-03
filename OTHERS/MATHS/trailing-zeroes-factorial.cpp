// NAIVE SOLUTION

int count(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f = f * i;

    int c = 0;
    while (f % 10 == 0)
    {
        c++;
        f = f / 10;
    }
    return c;
}

// OPTIMAL SOLUTION

int count(int n)
{
    int c = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        c += (n / i);
    }
    return c;
}
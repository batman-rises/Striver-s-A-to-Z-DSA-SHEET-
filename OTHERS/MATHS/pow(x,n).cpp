// Brute

int power(int x, int n)
{
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        c = c * i;
    }
    return c;
}

// Better

int pow(int x, int n)
{
    if (n == 0)
        return 1;

    int temp = pow(x, n / 2);
    temp = temp * temp;
    if (n % 2 == 0)
        return temp;
    else
        return temp * x;
}

// Optimal

int pow(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n % 2 != 0)
            res = res * x;
        x = x * x;
        n = n / 2;
    }
    return res;
}
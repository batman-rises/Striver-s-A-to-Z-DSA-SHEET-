// ITERATIVE

int fact(int n)
{
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact = fact * i;

    return fact;
}

// RECURSIVE

int fact(int n)
{
    if (n == 0)
        return 1;

    return n * fact(n - 1);
}
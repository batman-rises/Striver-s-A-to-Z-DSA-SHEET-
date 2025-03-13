// part 1

int func(int n)
{
    if (n <= 2)
        return n;

    return func(n - 1) + func(n - 2);
}

// part 2

int func(int n)
{
    if (n <= 2)
        return n;
    if (n == 3)
        return 4;
    return func(n - 1) + func(n - 2) + func(n - 3);
}
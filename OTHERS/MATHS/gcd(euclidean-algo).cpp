// BRUTE

int gcd(int a, int b)
{
    int c = min(a, b);
    while (a % c == 0 && b % c == 0)
    {
        break;
        c--;
    }
    return c;
}

// BETTER

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// OPTIMAL

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
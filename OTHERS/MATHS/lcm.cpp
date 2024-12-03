// BETTER

int lcm(int a, int b)
{
    int c = max(a, b);
    while (true)
    {
        if (c % a == 0 && c % b == 0)
        {
            return c;
        }
        c++;
    }
    return c;
}

// OPTIMAL

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
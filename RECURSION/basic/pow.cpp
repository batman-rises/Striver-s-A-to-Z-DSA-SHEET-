double pow(int x, int n)
{
    if (n == 0)
        return 1;

    long e = n;
    if (e < 0)
    {
        x = 1 / x;
        e = -e;
    }
    double half = pow(x, e / 2);
    if (x % 2 != 0)
        return half * half * x;
    else
        return half * half;
}
void print_divisors(int n)
{
    int i;
    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " "; // print all divisor from 1 to sqrt(n)
        }
    }

    for (i = i - 1; i >= 1; i--)
    {
        if (n % i == 0 && i != n / i)
        {
            cout << n / i << " "; // print all divisor from sqrt(n) to n
        }
    }
}
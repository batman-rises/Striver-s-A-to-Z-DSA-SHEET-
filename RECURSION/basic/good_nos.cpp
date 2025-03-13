class Solution
{
    const long MOD = 1'000'000'007;

public:
    int goodnos(long long n)
    {
        long even = (n + 1) / 2;
        long odd = n / 2;
        long ans = pow(5, even) * pow(4, odd);
        return (int)ans;
    }
}
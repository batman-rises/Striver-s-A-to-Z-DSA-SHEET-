int A2I(string s)
{
    int i = 0, sign = 1, res = 0;
    while (i < s.length() && s[i] == ' ')
        i++;

    while (i < s.length() && (s[i] == '+' || s[i] == '-'))
    {
        sign = s[i] == '-' ? -1 : 1;
        i++;
    }
    return helper(s, i, res, sign);
}
int helper(string s, int i, int res, int sign)
{
    if (i >= s.length() || !isdigit(s[i]))
        return res * sign;

    int a = s[i] = '0';

    if (res > (INT_MAX - a) / 10)
    {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }

    return helper(s, i + 1, res * 10 + a, sign);
}
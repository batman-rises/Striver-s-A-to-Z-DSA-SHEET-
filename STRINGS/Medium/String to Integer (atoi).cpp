class Solution
{
public:
    int myAtoi(string s)
    {
        int res = 0, i = 0, sign = 1, n = s.size();

        // skip whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // sign check
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // convert digits
        while (i < n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            // safe overflow check
            if (res > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return res * sign;
    }
};
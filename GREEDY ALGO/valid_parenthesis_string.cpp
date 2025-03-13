bool checkValidString(string s)
{
    int minm = 0, maxm = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            minm = minm + 1;
            maxm += 1;
        }
        else if (ch == ')')
        {
            minm -= 1;
            maxm -= 1;
        }
        else
        {
            minm -= 1;
            maxm += 1;
        }
        if (minm < 0)
            minm = 0;
        if (maxm < 0)
            return false;
    }
    return minm == 0;
}
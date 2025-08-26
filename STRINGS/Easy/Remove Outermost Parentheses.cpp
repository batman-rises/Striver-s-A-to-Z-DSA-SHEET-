class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        int c = 0;
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {

                if (c > 0)
                {
                    res += s[i];
                }
                c++;
            }
            else
            {
                c--;
                if (c > 0)
                {
                    res += s[i];
                }
            }
        }
        return res;
    }
};
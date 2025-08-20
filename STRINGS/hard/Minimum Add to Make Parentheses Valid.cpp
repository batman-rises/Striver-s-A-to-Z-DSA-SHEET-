class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int open = 0, insertions = 0;
        for (char c : s)
        {
            if (c == '(')
                open += 1;
            else
            {
                if (open > 0)
                {
                    open -= 1;
                }
                else
                {
                    insertions++;
                }
            }

            // maxi=max(maxi,close);
        }

        return open + insertions;
    }
};
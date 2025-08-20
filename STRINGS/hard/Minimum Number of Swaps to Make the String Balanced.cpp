class Solution
{
public:
    int minSwaps(string s)
    {
        int close = 0, maxi = 0;
        for (char c : s)
        {
            if (c == '[')
                close -= 1;
            else
                close += 1;
            maxi = max(maxi, close);
        }
        return (maxi + 1) / 2;
    }
};
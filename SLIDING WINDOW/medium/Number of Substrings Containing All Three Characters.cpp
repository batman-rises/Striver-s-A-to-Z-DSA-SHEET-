#include <bits/stdc++.h>
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        // int l=0,r=0;
        int cnt = 0;
        int lastseen[3] = {-1, -1, -1};

        for (int i = 0; i < n; i++)
        {
            lastseen[s[i] - 'a'] = i;
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
            {
                cnt += (1 + std::min({lastseen[0], lastseen[1], lastseen[2]}));
            }
        }
        return cnt;
    }
};
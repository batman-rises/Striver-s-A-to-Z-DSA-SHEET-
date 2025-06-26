class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        int hash[256];
        fill(hash, hash + 256, -1); // Initialize all elements to -1
        while (r < n)
        {
            if (hash[s[r]] != -1)
            { // if the character is already visited
                if (l <= hash[s[r]])
                {
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxlen = max(maxlen, len);

            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};
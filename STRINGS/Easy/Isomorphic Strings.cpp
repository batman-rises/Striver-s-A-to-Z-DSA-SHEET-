class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        int n = s.size();
        int m = t.size();
        if (n != m)
            return false;
        int i = 0;
        while (i < n)
        {
            if ((mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i]) || (mp2.find(t[i]) != mp2.end() && mp2[t[i]] != s[i]))
                return false;
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
            i++;
        }
        return true;
    }
};
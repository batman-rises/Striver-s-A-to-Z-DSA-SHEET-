class Solution
{
public:
    // Helper to trim leading/trailing spaces
    string trim(const string &s)
    {
        int start = 0, end = s.size() - 1;

        while (start <= end && isspace(s[start]))
            start++;
        while (end >= start && isspace(s[end]))
            end--;

        return s.substr(start, end - start + 1);
    }

    string reverseWords(string s)
    {
        s = trim(s);
        int n = s.size();
        string word = "", res = "";
        int i = 0;

        while (i < n)
        {
            char ch = s[i];
            if (ch != ' ')
            {
                word += ch;
            }
            else if (!word.empty())
            {
                res = word + " " + res;
                word = "";
            }
            i++;
        }

        if (!word.empty())
        {
            res = word + " " + res;
        }

        // Remove trailing space if any
        if (!res.empty() && res.back() == ' ')
        {
            res.pop_back();
        }

        return res;
    }
};

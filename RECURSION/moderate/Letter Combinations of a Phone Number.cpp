class Solution
{
    void func(int ind, string &digits, string &current, vector<string> &result, vector<string> &mapping)
    {
        if (ind == digits.size())
        {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[ind] - '0'];
        for (char ch : letters)
        {
            current.push_back(ch);
            func(ind + 1, digits, current, result, mapping);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string current;
        func(0, digits, current, res, mapping);
        return res;
    }
};
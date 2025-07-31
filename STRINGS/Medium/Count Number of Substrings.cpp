vector<string> findSubstrings(string &s)
{

    // to store all substrings
    vector<string> res;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {

            // substr function takes starting index
            // and length as parameters
            res.push_back(s.substr(i, j - i + 1));
        }
    }

    return res;
}

void occurences(string s, int i, int elm)
{
    int first = -1, last = -1;
    if (i == str.size())
    {
        cout << first << " & " << last << end;
        return;
    }
    if (str[i] == elm)
    {
        if (first == -1)
        {
            first = i;
        }
        else
        {
            last = i;
        }
    }
    occurences(s, i + 1, elm);
}
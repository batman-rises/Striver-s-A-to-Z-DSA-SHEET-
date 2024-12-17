int maxChildren(vector<int> &greed, vector<int> &cookie)
{
    int n = greed.size();
    int m = cookie.size();
    sort(greed.begin(), greed.end());
    sort(cookie.begin(), cookie.end());
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (greed[i] <= cookie[j])
        {
            i++;
        }
        j++;
    }
    return i;
}
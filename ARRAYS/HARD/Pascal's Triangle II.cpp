class Solution
{
public:
    vector<int> getRow(int n)
    {
        long long ans = 1;
        vector<int> row;
        row.push_back(1);
        for (int i = 1; i <= n; i++)
        {
            ans = ans * (n - i + 1);
            ans = ans / i;
            row.push_back(ans);
        }
        return row;
    }
};

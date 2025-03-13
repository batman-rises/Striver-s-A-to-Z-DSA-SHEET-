vector<string> binary_strs(int n)
{
    vector<string> res;

    string op = "";
    solve(n, op, '0', res);
    return res;
}
void solve(int n, string op, char lastch, vector<string> &res)
{
    if (n == 0)
    {
        res.push_back(op);
        return;
    }
    // 0 is always available
    solve(n - 1, op + '0', '0', res);
    // condn for 1...ie the last character shouldn't be 1
    if (lastch != '1')
    {
        solve(n - 1, op + '1', '1', res);
    }
}
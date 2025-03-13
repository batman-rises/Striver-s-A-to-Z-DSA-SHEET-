vector<string> n_bit_binary(int n)
{
    vector<string> res;
    int ones = n, zeros = n;
    string op = "";
    solve(ones, zeros, n, op, res);
    return res;
}
void solve(int ones, int zeros, int n, string op, vector<string> &res)
{
    if (n == 0)
    {
        res.push_back(op);
        return;
    }
    // 1 is always available
    string op1 = op;
    op1.push_back('1');
    solve(ones + 1, zeros, n - 1, op1, res);
    // condn for 0
    if (ones > zeros)
    {
        string op2 = op;
        op2.push_back('0');
        solve(open, close + 1, n - 1, op2, res);
    }
}
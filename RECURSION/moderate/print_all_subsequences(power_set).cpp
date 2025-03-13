vector<string> power_set(string str)
{
    string ip = str;
    string op = "";
    vector<string> res;
    solve(ip, op, res);
    return res;
}
void solve(string ip, string op, vector<string> &res)
{
    if (ip.size() == 0)
    {
        res.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    // op1 me kuch pick hi nhi karna rehta hai

    // op2
    op2.push_back(ip[0]);

    // deleting frist elm of input
    ip.erase(ip.begin() + 0);

    solve(ip, op1);
    solve(ip, op2);
}
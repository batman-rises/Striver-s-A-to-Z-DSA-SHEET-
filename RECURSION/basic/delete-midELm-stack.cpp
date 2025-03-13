stack<int> midElm(stack<int> &st, int size)
{
    if (size == 0)
        return st;

    int k = (st.size() + 1);

    solve(st, k);
    return st;
}
void solve(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    solve(st, k - 1);
    st.push(temp);
}
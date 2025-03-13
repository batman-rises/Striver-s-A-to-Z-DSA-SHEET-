void reverse(stack<int> &st)
{
    int n = st.size();
    if (n == 1)
        return;

    int temp = st.top();
    st.pop();

    reverse(st);
    insert(st, temp);
}
void insert(stack<int> &st, int temp)
{
    if (st.size() == 0)
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
}
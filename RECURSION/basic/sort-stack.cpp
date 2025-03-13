void sort(stack<int> &st)
{
    int n = st.size();
    if (n == 1)
        return;

    int temp = st.top();
    st.pop();

    sort(st);
    insert(st, temp);
}
void insert(stack<int> &st, int temp)
{
    if (st.size() == 0 || st.top() <= temp)
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
}
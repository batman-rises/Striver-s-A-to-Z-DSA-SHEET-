class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &a)
    {
        int n = a.size();
        vector<int> nge(n, 0);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= a[i % n])
            {
                st.pop();
            }
            if (i < n)
            {
                if (st.empty())
                {
                    nge[i] = -1;
                }
                else
                {
                    nge[i] = st.top();
                }
            }
            st.push(a[i % n]);
        }
        return nge;
    }
};
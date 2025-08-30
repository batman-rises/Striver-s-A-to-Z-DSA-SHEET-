class Solution
{
public:
    vector<int> leftSmaller(vector<int> a)
    {
        // code here
        stack<int> st;
        int n = a.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[i] <= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(a[i]);
        }
        return ans;
    }
};
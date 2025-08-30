class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= a[i])
            {
                st.pop();
            }

            ans[i] = st.size();

            st.push(a[i]);
        }
        return ans;
    }
};
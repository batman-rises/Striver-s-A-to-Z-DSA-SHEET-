class Solution
{
public:
    vector<int> NSE(vector<int> &a, int n)
    {
        stack<int> st;
        vector<int> nse(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && a[st.top()] >= a[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> PSEE(vector<int> &a, int n)
    {
        stack<int> st;
        vector<int> pse(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[st.top()] > a[i])
            {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int> &a)
    {
        int n = a.size();
        vector<int> nse = NSE(a, n);
        vector<int> pse = PSEE(a, n);
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (left * right % mod * a[i] % mod)) % mod;
        }
        return (int)total;
    }
};
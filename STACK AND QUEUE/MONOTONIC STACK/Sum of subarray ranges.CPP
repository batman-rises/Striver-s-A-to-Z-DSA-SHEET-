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
                st.pop();
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
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    long long sumSubarrayMins(vector<int> &a, int n)
    {
        vector<int> nse = NSE(a, n);
        vector<int> pse = PSEE(a, n);

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += left * right * 1LL * a[i];
        }
        return total;
    }

    vector<int> NGE(vector<int> &a, int n)
    {
        stack<int> st;
        vector<int> nge(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && a[st.top()] <= a[i])
                st.pop();
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> PGEE(vector<int> &a, int n)
    {
        stack<int> st;
        vector<int> pge(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[st.top()] < a[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMaxms(vector<int> &a, int n)
    {
        vector<int> nge = NGE(a, n);
        vector<int> pge = PGEE(a, n);

        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += left * right * 1LL * a[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        return sumSubarrayMaxms(nums, n) - sumSubarrayMins(nums, n);
    }
};

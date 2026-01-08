class Solution
{
public:
    int func(vector<int> &a, int maxi)
    {
        int cnt = 1;
        int lastCoordinate = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] - lastCoordinate >= maxi)
            {
                cnt++;
                lastCoordinate = a[i];
            }
        }
        return cnt;
    }
    int aggressiveCows(vector<int> &a, int k)
    {
        // code here
        sort(a.begin(), a.end());
        int l = 1;
        int n = a.size();
        int maxi = a[n - 1];
        int mini = a[0];
        int h = (maxi - mini);
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int cows = func(a, mid);
            if (cows >= k)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return h;
    }
};
class Solution
{
public:
    void nearlySorted(vector<int> &arr, int k)
    {
        // code
        int n = arr.size();
        vector<int> temp(n);
        int index = 0;
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int i = 0; i < n; i++)
        {
            minH.push(arr[i]);

            if (minH.size() > k)
            {
                arr[index++] = minH.top();
                minH.pop();
            }
        }
        while (!minH.empty())
        {
            arr[index++] = minH.top();
            minH.pop();
        }
    }
};
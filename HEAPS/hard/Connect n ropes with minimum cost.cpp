int minCost(vector<int> &arr)
{
    // code here
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> h;
    for (int i = 0; i < n; i++)
    {
        h.push(arr[i]);
    }
    int s = 0;
    while (h.size() >= 2)
    {
        int first = h.top();
        h.pop();
        int second = h.top();
        h.pop();
        s += first + second;
        h.push(first + second);
    }
    return s;
}
// User function template for C++

class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        priority_queue<int> maxH;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            maxH.push(arr[i]);
            if (maxH.size() > k)
                maxH.pop();
        }
        return maxH.top();
    }
};
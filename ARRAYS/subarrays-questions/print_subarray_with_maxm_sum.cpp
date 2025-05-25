vector<int> func(vector<int> &arr, int n)
{
    int sum = 0, maxi = INT_MIN; // Use INT_MIN to handle all-negative case
    int ansStart = -1, ansEnd = -1, start = 0;

    // Edge case: empty array
    if (n == 0)
        return {};

    // Kadane's Algorithm to find max subarray sum and indices
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i; // Reset start when sum becomes 0
        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
            sum = 0; // Reset sum if negative
    }

    // If no positive sum found, find the largest single element
    if (maxi <= 0)
    {
        maxi = arr[0];
        ansStart = ansEnd = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > maxi)
            {
                maxi = arr[i];
                ansStart = ansEnd = i;
            }
        }
    }

    // Build the result subarray
    vector<int> ans;
    for (int i = ansStart; i <= ansEnd; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for (int i = 0; i <= (n / 2 - 1); i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // Parent should be >= children
            if (left < n && arr[i] < arr[left])
                return false;
            if (right < n && arr[i] < arr[right])
                return false;
        }
        return true;
    }
};
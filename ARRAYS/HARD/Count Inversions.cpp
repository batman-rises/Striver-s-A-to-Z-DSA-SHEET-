class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        int cnt = 0;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            { // when left is greater then right
                cnt += (mid - left + 1);
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }

    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};
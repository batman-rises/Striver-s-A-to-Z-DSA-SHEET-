class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                if (sum == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};
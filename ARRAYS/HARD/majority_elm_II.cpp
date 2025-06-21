class Solution
{
public:
    vector<int> majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && arr[i] != el2)
            {
                cnt1 = 1;
                el1 = arr[i];
            }
            else if (cnt2 == 0 && arr[i] != el1)
            {
                cnt2 = 1;
                el2 = arr[i];
            }
            else if (arr[i] == el1)
                cnt1++;
            else if (arr[i] == el2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (el1 == arr[i])
                cnt1++;
            if (el2 == arr[i])
                cnt2++;
        }
        int minm = (int)(n / 3) + 1;

        if (cnt1 >= minm)
            ans.push_back(el1);
        if (cnt2 >= minm)
            ans.push_back(el2);
        return ans;
    }
};
class Solution
{
public:
    int totalFruit(vector<int> &arr)
    {
        int k = 2;
        int n = arr.size();
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[arr[r]]++;
            // if(mp.size() > k){
            while (mp.size() > k)
            {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)
                    mp.erase(arr[l]);

                l++;
            }
            //}
            if (mp.size() <= k)
            {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};
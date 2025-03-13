int findPlatform(vector<int> &arr, vector<int> &dep)
{ 
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0;
    int cnt = 0, maxi = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}
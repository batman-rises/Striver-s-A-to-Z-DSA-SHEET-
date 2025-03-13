void sortRec(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return;
    int temp = arr[n - 1];
    arr.pop_back();
    sortRec(arr);
    ins(arr, temp);
}
void ins(vector<int> &arr, int temp)
{
    if (arr.size() == 0 || arr[i] <= temp)
    {
        arr.push_back(temp);
        return;
    }
    int val = arr[n - 1];
    arr.pop_back();
    ins(arr, temp);
    arr.push_back(val);
}
vector<int> ss(vector<int> arr, int n)
{
    vector<int> sum;
    func(0, 0, arr, n, sum);
    sort(sum.begin(), sum.end());
    return sum;
}
void func(int i, int s, vector<int> arr, int n, vector<int> sum)
{
    if (i == n)
    {
        sum.push_back(s);
        return;
    }
    // pick
    func(i + 1, s + arr[i], arr, n, sum);
    // not pick
    func(i + 1, s, arr, n, sum);
}
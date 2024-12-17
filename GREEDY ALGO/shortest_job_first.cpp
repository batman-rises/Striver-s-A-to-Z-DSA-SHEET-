long long solve(vector<int> &bt)
{
    int n = bt.size();
    sort(bt.begin(), bt.end());
    int time = 0, waitingTime = 0;
    for (int i = 0; i < n; i++)
    {
        waitingTime += time;
        time += bt[i];
    }
    return waitingTime / n;
}
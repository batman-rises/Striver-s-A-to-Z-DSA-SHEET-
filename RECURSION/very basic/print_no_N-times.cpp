
// 1 to n
vector<int> func(int n)
{
    if (n == 0)
        return {}; // Base case: return empty vector

    vector<int> res = func(n - 1); // Get result from recursive call
    res.push_back(n);              // Append current number
    return res;
}
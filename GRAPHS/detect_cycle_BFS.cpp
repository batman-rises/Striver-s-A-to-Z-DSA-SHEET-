bool detect(int src, vector<vector<int>> adj, int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto adjN : adj[node])
        {
            if (!vis[adjN])
            {
                vis[adjN] = 1;
                q.push({adjN, node});
            }
            else if (adjN != parent)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(vector<vector<int>> &adj)
{
    // Code here
    int n = adj.size();
    int vis[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
                return true;
        }
    }
    return false;
}
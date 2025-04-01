bool isSafe(int node, vector<int> &color, vector<vector<int>> &adj, int colour)
{
    for (int neighbor : adj[node])
    { // Iterate through adjacency list
        if (color[neighbor] == colour)
            return false;
    }
    return true;
}

bool solve(int node, vector<int> &color, int m, vector<vector<int>> &adj, int V)
{
    if (node == V)
        return true; // All nodes colored successfully

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(node, color, adj, c))
        {
            color[node] = c;
            if (solve(node + 1, color, m, adj, V))
                return true;
            color[node] = 0; // Backtrack
        }
    }
    return false;
}

bool graphColoring(int V, vector<pair<int, int>> &edges, int m)
{
    vector<vector<int>> adj(V);
    for (auto edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    vector<int> color(V, 0); // 0 means uncolored
    return solve(0, color, m, adj, V);
}
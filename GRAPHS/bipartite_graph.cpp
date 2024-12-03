class Solution
{
private:
    bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &graph)
    {
        color[node] = col;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            { // If not yet colored
                if (!dfs(it, 1 - col, color, graph))
                    return false;
            }
            else if (color[it] == col)
            { // Adjacent node has same color
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1); // -1 means uncolored

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            { // Not visited
                if (!dfs(i, 0, color, graph))
                    return false;
            }
        }
        return true;
    }
};
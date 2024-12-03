#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfsOfGraph(std::vector<std::vector<int>> &adj)
{
    int n = adj.size();   // Number of nodes in the graph
    int vis[n] = {0};     // Visited array to keep track of visited nodes
    vis[0] = 1;           // Mark the starting node as visited
    std::queue<int> q;    // Queue for BFS traversal
    q.push(0);            // Start BFS from node 0
    std::vector<int> ans; // Result to store the BFS order

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node); // Add the current node to the BFS result
        for (auto it : adj[node])
        {
            if (!vis[it])
            {                // If the adjacent node is not visited
                vis[it] = 1; // Mark it as visited
                q.push(it);  // Push it into the queue
            }
        }
    }
    return ans;
}

int main()
{
    // Example graph as adjacency list
    std::vector<std::vector<int>> adj = {
        {1, 2},    // Node 0 is connected to 1 and 2
        {0, 3, 4}, // Node 1 is connected to 0, 3, and 4
        {0},       // Node 2 is connected to 0
        {1},       // Node 3 is connected to 1
        {1}        // Node 4 is connected to 1
    };

    std::vector<int> bfsResult = bfsOfGraph(adj);

    std::cout << "BFS Traversal: ";
    for (int node : bfsResult)
    {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}

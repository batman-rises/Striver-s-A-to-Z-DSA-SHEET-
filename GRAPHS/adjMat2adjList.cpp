#include <iostream>
#include <vector>
#include <utility> // for std::pair

// Function to create and return an adjacency list representation of the graph
std::vector<std::vector<int>> printGraph(int V, std::vector<std::pair<int, int>> &edges)
{
    std::vector<std::vector<int>> adjLs(V); // Adjacency list for V vertices
    for (auto edge : edges)
    {
        int u = edge.first;    // First vertex of the edge
        int v = edge.second;   // Second vertex of the edge
        adjLs[u].push_back(v); // Add v to the adjacency list of u
        adjLs[v].push_back(u); // Add u to the adjacency list of v (for undirected graph)
    }
    return adjLs;
}

// Helper function to print the adjacency list
void displayAdjList(const std::vector<std::vector<int>> &adjLs)
{
    for (int i = 0; i < adjLs.size(); i++)
    {
        std::cout << i << ": ";
        for (int neighbor : adjLs[i])
        {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int V = 5; // Number of vertices
    std::vector<std::pair<int, int>> edges = {
        {0, 1}, {0, 4}, {1, 4}, {1, 2}, {1, 3}, {3, 4}};

    std::vector<std::vector<int>> adjList = printGraph(V, edges);

    std::cout << "Adjacency List:" << std::endl;
    displayAdjList(adjList);

    return 0;
}

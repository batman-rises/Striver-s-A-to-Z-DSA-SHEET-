// Given an integer n representing number of vertices.
// Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.
#include <iostream>
#include <cmath> // for pow function

long long count(int n)
{
    int e = (n * (n - 1)) / 2; // Calculate the number of edges in a complete graph with n vertices
    return pow(2, e);          // Calculate 2 raised to the power of e
}

int main()
{
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    long long result = count(n);
    std::cout << "The result is: " << result << std::endl;

    return 0;
}

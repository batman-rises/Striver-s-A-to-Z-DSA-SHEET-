int extractMax()
{
    // your code here
    if (s == -1)
        return INT_MIN; // Empty heap

    int maxElement = H[0]; // Store max
    H[0] = H[s];           // Replace with last
    s--;                   // Decrease size

    if (s >= 0)
        shiftDown(0); // Restore heap property

    return maxElement;
}
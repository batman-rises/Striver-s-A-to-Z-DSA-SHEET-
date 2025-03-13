struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();

        // Create a vector of Items
        vector<Item> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i].value = val[i];
            arr[i].weight = wt[i];
        }

        // Sort items by value-to-weight ratio in descending order
        sort(arr.begin(), arr.end(), [](Item a, Item b)
             { return (double)a.value / a.weight > (double)b.value / b.weight; });

        double total = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= capacity)
            {
                capacity -= arr[i].weight;
                total += arr[i].value;
            }
            else
            {
                total += (double)arr[i].value / arr[i].weight * capacity;
                break;
            }
        }
        return total;
    }
};

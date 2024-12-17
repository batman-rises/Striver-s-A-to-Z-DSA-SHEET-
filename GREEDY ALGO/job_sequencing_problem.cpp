typedef struct
{
    int id;
    int profit;
    int deadline;
} jobs;

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
{
    vector<int> ans;

    int n = id.size();
    jobs arr[n];

    // Step 1: Store job data in the struct array
    for (int i = 0; i < n; i++)
    {
        arr[i].id = id[i];
        arr[i].deadline = deadline[i];
        arr[i].profit = profit[i];
    }

    // Step 2: Sort jobs in descending order of profit
    sort(arr, arr + n, [](jobs a, jobs b)
         { return a.profit > b.profit; });
    // Step 3: Find the maximum deadline
    int maxDeadline = -1;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    // Step 4: Allocate slots and calculate total profit
    vector<int> slots(maxDeadline + 1, -1); // To track free slots
    int totalProfit = 0, jobsCount = 0;

    for (int i = 0; i < n; i++)
    {
        // Try to place the current job at its deadline or before
        for (int j = arr[i].deadline; j > 0; j--)
        { // Deadline is 1-based
            if (slots[j] == -1)
            {                                 // Free slot found
                slots[j] = arr[i].id;         // Assign job to the slot
                totalProfit += arr[i].profit; // Add profit
                jobsCount++;                  // Increment job count
                break;
            }
        }
    }

    // Step 5: Return job count and total profit
    ans.push_back(jobsCount);
    ans.push_back(totalProfit);
    return ans;
}
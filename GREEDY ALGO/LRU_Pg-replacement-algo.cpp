int pageFaults(int n, int C, int pages[])
{
    unordered_set<int> memory;
    list<int> usageOrder;
    int pgFault = 0;

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        // ig pg is not in the memory
        if (memory.find(page) == memory.end())
        {
            pgFault++;

            // if memory is full remove LRU pg
            if (memory.size() == C)
            {
                int lru = usageOrder.front();
                usageOrder.pop_front();
                memory.erase(lru);
            }
            memory.insert(page);
        }
        else
        {
            usageOrder.remove(page);
        }
        usageOrder.push_back(page);
    }
    return pgFault;
}
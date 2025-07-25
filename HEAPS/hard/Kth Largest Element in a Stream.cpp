class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        // priority_queue<int,vector<int>,greater<int>>pq;
        this->k = k;
        for (int &n : nums)
        {
            pq.push(n);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
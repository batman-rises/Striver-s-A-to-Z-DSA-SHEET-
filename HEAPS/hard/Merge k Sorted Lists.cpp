class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;

        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> h;
        for (auto head : lists)
        {
            if (head != NULL)
                h.push({head->val, head});
        }
        while (!h.empty())
        {
            ListNode *minNode = h.top().second;
            h.pop();

            if (minNode->next != NULL)
            {
                h.push({minNode->next->val, minNode->next});
            }
            dummyTail->next = minNode;
            dummyTail = dummyTail->next;
        }
        return dummyHead->next;
    }
};
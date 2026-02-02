class Solution {
public:
    int lengthOFCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int cnt=1;
                fast=fast->next;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                    cnt++;
                }
                return cnt;

            }
        }
        return -1;
    }
};
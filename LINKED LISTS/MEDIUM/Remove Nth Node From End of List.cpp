class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        //edge case
        if(fast==NULL){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        ListNode* slow=head;
        while(fast->next != NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* x=slow->next;
        slow->next=slow->next->next;
        delete x;
        return head;
    }
};
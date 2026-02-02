class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead=new ListNode(-1);
        ListNode* cur=dummyHead;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;

        while(temp1!=NULL || temp2!=NULL){
            int s=carry;
            if(temp1){
                s+=temp1->val;
            }
            if(temp2){
                s+=temp2->val;
            }
            ListNode* newNode=new ListNode(s%10);
            carry=s/10;
            cur->next=newNode;
            cur=cur->next;
            if(temp1){
                temp1=temp1->next;
            }
            if(temp2){
                temp2=temp2->next;
            }
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            cur->next=newNode;
        }
        return dummyHead->next;
    }
};
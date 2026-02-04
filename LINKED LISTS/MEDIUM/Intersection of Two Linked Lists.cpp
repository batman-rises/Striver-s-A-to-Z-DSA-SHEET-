class Solution {
public:
    int countLength(ListNode *head){
        ListNode *temp=head;
        int c=1;
        while(temp){
            c++;
            temp=temp->next;
        }
        return c;
    }
    ListNode *collisionPoint(ListNode *small, ListNode *big,int d){
        while(d){
            d--;
            big=big->next;
        }
        while(small != big){
            small=small->next;
            big=big->next;
        }
        return small;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1=headA;
        int n=countLength(t1);
        ListNode *t2=headB;
        int m=countLength(t2);
        if(n<m){                //smaller,bigger
            return collisionPoint(t1,t2,m-n);
        }else{
            return collisionPoint(t2,t1,n-m);
        }
    }
};
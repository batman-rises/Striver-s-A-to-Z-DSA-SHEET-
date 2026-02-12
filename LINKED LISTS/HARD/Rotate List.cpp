ListNode* func(ListNode* head, int k){
        ListNode* temp=head;
        k=k-1;
        while(k--){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        int len=1;
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
            len++;
        }
        if(k%len==0)return head;
        temp->next=head;
        k=k%len;
        ListNode* newTail=func(head,len-k);
        ListNode* newHead=newTail->next;
        newTail->next=NULL;
        return newHead;
    }
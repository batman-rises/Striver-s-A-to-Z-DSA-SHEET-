class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        struct Node *temp=head;
        while(temp && temp->next!=NULL){
            struct Node *nextNode=temp->next;
            while(nextNode!=NULL && temp->data==nextNode->data){
                struct Node *dup=nextNode;
                nextNode=nextNode->next;
                free(dup);
            }
            temp->next=nextNode;
            if(nextNode)nextNode->prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
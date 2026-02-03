/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* rev(Node* head){
        Node* cur=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(cur){
            next=cur->next;
            cur->next=prev;
            
            prev=cur;
            cur=next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        Node* revHead=rev(head);
        Node* temp=revHead;
        int carry=1;
        while(temp){
            temp->data=temp->data+carry;
            if(temp->data < 10){
                carry=0;
                break;
            }else{
                temp->data=0;
                carry=1;
            }
            temp=temp->next;
        }
        if(carry==1){
            Node* n=new Node(1);
            n->next=revHead;
            return n;
        }
        head=rev(revHead);
        return head;
        // return head of list after adding one
    }
};
/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node *l1,Node *l2){
        Node *t1=l1;
        Node *t2=l2;
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        while(t1 && t2){
            if(t1->data < t2->data){
                temp->bottom=t1;
                temp=t1;
                t1=t1->bottom;
            }else{
                temp->bottom=t2;
                temp=t2;
                t2=t2->bottom;
            }
        }
        if(t1)temp->bottom=t1;
        if(t2)temp->bottom=t2;
        return dummy->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(root==NULL){
            return NULL;
        }
        Node* head2=flatten(root->next);
        return merge(root,head2);
        
    }
};
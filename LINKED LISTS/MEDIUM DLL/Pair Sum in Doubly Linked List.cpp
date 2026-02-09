
class Solution {
  public:
    Node *findTail(Node *head){
        Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        return temp;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int X) {
        // code here
        Node *left=head;
        vector<pair<int, int>> ans;
        Node *right=findTail(head);
        while(left->data < right->data){
            if(left->data + right->data == X){
                ans.push_back({left->data , right->data});
                left=left->next;
                right=right->prev;
            }else if(left->data + right->data < X){
                left=left->next;
            }else{
                right=right->prev;
            }
        }
        return ans;
    }
    
};
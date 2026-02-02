//BRUTE

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* temp=head;
        int c0=0,c1=0,c2=0;
        while(temp){
            if(temp->data == 0){
                c0++;
            }else if(temp->data == 1){
                c1++;
            }else{
                c2++;
            }
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(c0){
                temp->data=0;
                c0--;
            }else if(c1){
                temp->data=1;
                c1--;
            }else{
                temp->data=2;
                c2--;
            }
            temp=temp->next;
        }
        return head;
    }
};

//OPTIMAL
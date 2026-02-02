//BRUTE

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>a;
        ListNode* temp=head;
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }
        sort(a.begin(),a.end());
        temp=head;
        int i=0;
        while(temp){
            temp->val=a[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};
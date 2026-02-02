//brute
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(st.top() != temp->val)return false;
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};

//optimal
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* temp=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(temp){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
       //step 1: find the middle node
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
       //step 2: divide the list into two halves,
       //step 3 : reverse the second half
       ListNode* newHead=rev(slow->next);
       ListNode* first=head;
       ListNode* second=newHead;
       //step 4 : match
       while(second){
        if(first->val != second->val){
            rev(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
       }
       rev(newHead);
       return true;
    }
};
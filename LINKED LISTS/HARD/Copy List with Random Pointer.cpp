class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* newHead=new Node(head->val);
        Node* oldTemp=head->next;
        Node* newTemp=newHead;
        unordered_map<Node*,Node*>mp;
        mp[head]=newHead;
        while(oldTemp){
            Node* copyNode=new Node(oldTemp->val);
            mp[oldTemp]=copyNode;

            newTemp->next=copyNode;

            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
        newTemp=newHead;
        oldTemp=head;
        while(oldTemp){
            newTemp->random=mp[oldTemp->random];
             oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
        return newHead;
    }
};
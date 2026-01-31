Node* reverse(Node* head){
    stack<int>st;
    Node* temp=head;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}


func(head){
    //base casee 

    //logic
    curr=head;
    last=nullptr;
    while(curr){
        last=curr->prev;

        //swapping
        curr->prev=curr->next;
        curr->next=last;

        //move forward
        curr=curr->prev;
    }
    return last->prev;
}
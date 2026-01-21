//insert to head
Node* func(head,val){
    return new Node(val,head);
}


//insert to end
Node* func(head,val){
    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* n= new Node(val);
    temp->next=n;
    return head;
}


//insert at kth position
Node* func(head,val,k){
    //edge case
    if (head == NULL) {
        if (k == 1) return new Node(val);
        else return NULL;
    }
    if(k==1)return new Node(val,head);

    int cnt=0;
    Node* temp=head;
    while(temp->next != NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x=new Node(val,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}


//insert before a particular value
Node* func(head,val){
    //edge case
    if(head==null)return new Node(val);
    if (head->data == target) {
        return new Node(newVal, head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x=new Node(val,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int func(head,val){
    int cnt=0;
    Node* temp=head;
    while(temp){
        if(temp->data == val)
        return 1;
        temp=temp->next;
    }
    return 0;
}
//head
Node* func(head,val){
    Node* n=new Node(val,head,nullptr);

    if(head==NULL)
    return n;
    else{
        head=->back=n;
        head=n;
        return head;
    }
    
}


//tail
Node* func(head,val){
    if(head==NULL || head->next==NULL)
    return insertBeforeHead(head,val)

    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
        
    }
    Node* prev=temp->back;
    Node* n=new Node(val,temp,prev);

    prev->=temp->back=n;
    return head;
}

//kth elm
Node* func(head){
    if(k==1)
    return insertBeforeHead(head,val)

    Node* temp=head;
    int c=0;
    while(temp->next != NULL){
        c++;
        if(c==k)
            break;
        temp=temp->next;
        
    }
   
    prev=temp->back;
    Node* n=new Node(val,temp,prev);
   
    prev->next=n;
    temp->back=n;
    return head;
}
//given node

void deleteNode(Node* node) {
    Node* prev = node->back;
    Node* n=new Node(val,node,prev);


    node->back = prev->next = n;
}
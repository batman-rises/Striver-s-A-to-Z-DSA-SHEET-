//head
Node* func(head){
    if(head==NULL || head->next==NULL)
    return NULL;

    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}


//tail
Node* func(head){
    if(head==NULL || head->next==NULL)
    return NULL;

    Node* temp=head;
    Node* prev=NULL;
    while(temp->next != NULL){
        temp=temp->next;
        //prev=temp;
    }
    prev=temp->back;
    prev->next=nullptr;
    temp->back=nullptr;
   
    delete temp;
    return head;
}

//kth elm
Node* func(head){
    if(head==NULL || head->next==NULL)
    return NULL;

    Node* temp=head;
    Node* prev=NULL;
    Node* front=NULL;
    int c=0;
    while(temp->next != NULL){
        c++;
        if(c==k)
            break;
        temp=temp->next;
        
    }
   
    prev=temp->back;
    front=temp->next;
    if(prev==NULL)//first elm
        return deleteHead(head);
    else if(front==NULL)//last elm
        return deleteTail(head);

    prev->next=front;
    front->back=prev;

    temp->next=temp->back=nullptr;


    delete temp;
    return head;
}
//given node

void deleteNode(Node* node) {
    Node* prev = node->back;
    Node* front = node->next;

    if (prev != nullptr) prev->next = front;
    if (front != nullptr) front->back = prev;

    node->next = node->back = nullptr;
    delete node;
}
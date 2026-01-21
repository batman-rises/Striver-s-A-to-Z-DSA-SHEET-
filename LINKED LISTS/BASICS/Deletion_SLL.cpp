//delete head
Node* func(head,val){
    if(head==null)
    return null;
    if(head->next==null)return null;

    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

//delete tail
Node* func(head,val){

    if(head==null)
    return null;
    if(head->next==null)return null;

    Node* temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}

//delete Kth elm

    if(head==null)
    return null;
    if(head->next==null)return null;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=null;
    while(temp!= NULL){
        cnt++;
        if(cnt==k){
            prev->next=temp->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
  
    return head;

//delete given value

 if(head==null)
    return null;
    if(head->next==null)return null;
    if(head->data==el){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=null;
    while(temp!= NULL){
        if(temp->data==el){
            prev->next=temp->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    
    return head;
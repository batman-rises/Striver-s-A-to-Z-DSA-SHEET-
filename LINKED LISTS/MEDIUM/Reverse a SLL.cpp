Node* reverse(Node* head) {
    Node* prev = NULL;   
    Node* curr = head;   
    Node* next = NULL;   

    while (curr != NULL) {
        next = curr->next; // Save the next node (so we don't lose it)
        curr->next = prev; // Flip the arrow! (Current points back to previous)
        prev = curr;       // Move 'prev' one step forward
        curr = next;       // Move 'curr' one step forward
    }
    
    return prev; // 'prev' is the new head of the reversed list
}
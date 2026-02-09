/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
    struct Node* curr = *head;
    
    while (curr != NULL) {
        if (curr->data == x) {
            struct Node* nodeToDelete = curr;
            
            // 1. If it's the head node, move the head pointer forward
            if (nodeToDelete == *head) {
                *head = nodeToDelete->next;
            }

            // 2. Link PREV node to NEXT node
            if (nodeToDelete->prev != NULL) {
                nodeToDelete->prev->next = nodeToDelete->next;
            }

            // 3. Link NEXT node to PREV node
            if (nodeToDelete->next != NULL) {
                nodeToDelete->next->prev = nodeToDelete->prev;
            }

            // Move curr to next node before freeing memory
            curr = nodeToDelete->next;
            free(nodeToDelete);
        } else {
            curr = curr->next;
        }
    }
}
};
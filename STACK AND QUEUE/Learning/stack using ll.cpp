class st
{
    Node *top = null;
    int size = 0;
    push(x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }
    int pop()
    {
        if (top == null)
            return -1;
        Node *temp = top;
        int el = temp->data;
        top = top->next;
        delete temp;
        return el;
    }
}
class st_implementation
{
    int top = -1, st[10];
    void push(x)
    {
        if (top >= 9)
            print("size exceed");
        top++;
        st[top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            print("empty stack");
            return -1;
        }
        int el = st[top];
        top--;
        return el;
    }
    int size()
    {
        return top + 1;
    }
}
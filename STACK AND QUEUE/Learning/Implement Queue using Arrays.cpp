class Q
{
    int q[10], size = 0, front = -1, rear = -1;
    void push(int x)
    {
        if (size >= 9)
            print("queue full");
        if (size == 0)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % 10; // cyclic nature
        }
        q[rear] = x;
        size++;
    }
    int pop()
    {
        if (size == 0)
        {
            print("queue already empty");
            return -1;
        }
        if (rear <= front)
            return -1;
        int el = q[front];
        if (size == 1)
        { // reset when last element removed
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % 10; // cyclic increment
        }
        size--;
        return el;
    }
}
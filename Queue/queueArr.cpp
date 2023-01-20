

class Queue
{
    int ms;
    int cs;
    int front;
    int rear;
    int *arr;

public:
    Queue(int size = 5)
    {
        arr = new int[size];
        ms = size;
        cs = 0;
        front = 0;
        rear = ms - 1;
    }
    bool full()
    {
        return cs == ms;
    }
    bool empty()
    {
        return cs == 0;
    }
    void push(int data)
    {
        if (!full())
        {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }
    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % ms;
            cs--;
        }
    }
    int getfront()
    {
        return arr[front];
    }
};
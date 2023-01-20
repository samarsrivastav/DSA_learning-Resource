#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Stack
{
    queue<int> q1, q2;

public:
    void push(int d)
    {
        if (!q1.empty())
        {
            q1.push(d);
        }
        else
        {
            q2.push(d);
        }
    }
    void pop()
    {
        if (q1.empty())
        {
            while (!q2.empty())
            {
                int front = q2.front();
                q2.pop();
                if (q2.empty())
                {
                    break;
                }
                q1.push(front);
            }
        }
        else
        {
            while (!q1.empty())
            {
                int front = q1.front();
                q1.pop();
                if (q1.empty())
                {
                    break;
                }
                q2.push(front);
            }
        }
    }
    int top()
    {
        int ans = 0;
        if (q1.empty())
        {
            while (!q2.empty())
            {
                int front = q2.front();
                q1.push(front);
                q2.pop();
                if (q2.empty())
                {
                    ans = front;
                    break;
                }
            }
        }
        else
        {
            while (!q1.empty())
            {
                int front = q1.front();
                q2.push(front);
                q1.pop();
                if (q1.empty())
                {
                    ans = front;
                    break;
                }
            }
        }
        return ans;
    }
    bool empty()
    {
        if (q1.empty() and q2.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(4);
    s.pop();
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
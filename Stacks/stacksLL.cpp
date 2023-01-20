
template <typename t>
class node
{
public:
    t data;
    node<t> *next;
    node(t d)
    {
        data = d;
    }
};
template <typename t>
class stack
{
    node<t> *head;

public:
    stack()
    {
        head = NULL;
    }
    bool empty()
    {
        return head == NULL;
    }
    void pop()
    {
        node<t> *temp = head;
        head = head->next;
        delete temp;
    }
    t top()
    {
        return head->data;
    }
    void push(t d)
    {
        node <t>*n = new node<t>(d);
        n->next = head;
        head = n;
    }
};
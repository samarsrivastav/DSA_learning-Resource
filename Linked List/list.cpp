#include <bits\stdc++.h>
using namespace std;
class Node
{

    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {}

    int getdata()
    {
        return data;
    }
    friend class List;
};
class List
{
    Node *head;
    Node *tail;
    int helper(Node *start, int key)
    {
        if (start == NULL)
        {
            return -1;
        }
        if (start->data == key)
        {
            return 0;
        }
        int idx = helper(start->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }

public:
    List() : head(NULL), tail(NULL) {}
    Node *begin()
    {
        return head;
    }
    void push_front(int d)
    {
        if (head == NULL)
        {
            Node *n = new Node(d);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(d);
            n->next = head;
            head = n;
        }
    }
    void push_back(int d)
    {
        if (head == NULL)
        {
            Node *n = new Node(d);
            head = tail = n;
        }
        else
        {
            Node *n = new Node(d);
            tail->next = n;
            tail = n;
        }
    }
    void insert(int d, int pos)
    {
        if (pos == 0)
        {
            push_front(d);
            return;
        }
        else
        {
            Node *n = new Node(d);
            Node *temp = head;
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
    int search(int key)
    {
        int idx = helper(head, key);
        return idx;
    }
    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    Node *popBack()
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            delete (head);
            return NULL;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
        return head;
    }
    void remove(int pos)
    {
        Node *temp = head;
        if (pos == 0)
        {
            head = temp->next;
            delete temp;
            return;
        }
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        Node *n = temp->next;
        temp->next = n->next;
        n->next = NULL;
        delete n;
    }
    void reverse()
    {
        Node *p = NULL;
        Node *c = head;
        Node *n = NULL;
        while (c != NULL)
        {
            n = c->next;
            c->next = p;

            p = c;
            c = n;
        }
        head = p;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->getdata() << "->";
            temp = temp->next;
        }
    }
};

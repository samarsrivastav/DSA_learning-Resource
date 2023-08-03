#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T value;
    node *next;
    node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    // ~Node(){
	// 	if(next!=NULL){
	// 		delete next;
	// 	}
	// }
};
template <typename T>
class hashtable
{
    node<T> **table;
    int cs;
    int ts;
    int hashFn(string key)
    {
        int idx = 0;
        int power = 1;
        for (auto c : key)
        {
            idx = (idx + c * power) % ts;
            power = (power * 29) % ts;
        }
        return idx;
    }
    void rehash()
    {
        node<T> **oldTable = table;
        int OldTs = ts;

        cs = 0;
        ts = ts * 2 + 1;
        table =new node<T>*[ts];

        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
        // copy the elements

        for (int i = 0; i < OldTs; i++)
        {
            node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                string key = temp->key;
                T value = temp->value;
                insert(key, value);
                temp = temp->next;
            }
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    hashtable(int default_size = 7)
    {
        cs = 0;
        ts = default_size;
        table = new node<T> *[ts];
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(string key, T value)
    {
        int idx = hashFn(key);
        node<T> *n = new node<T>(key, value);
        n->next = table[idx];
        table[idx] = n;
        cs++;

        float load_factor = cs / float(ts);
        if (load_factor > 0.7)
        {
            rehash();
        }
    }
    void print(){
        for (int i = 0; i < ts; i++)
        {
            cout<<"bucket :"<<i<<"-> ";
          node<T>* temp =table[i];
          while (temp!=NULL)
          { 
            cout<<"( "<<temp->key<<","<<temp->value<<" ) -->";
            temp=temp->next;
          }
          cout<<endl;
        }
    }
};

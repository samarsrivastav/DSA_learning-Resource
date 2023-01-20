#include <bits/stdc++.h>
#include "list.cpp"
using namespace std;

int main()
{

    List l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(3);
    l.push_back(8);
    l.push_back(3);
    l.push_front(0);
    l.insert(2, 2);
    l.popBack();
    
    l.reverse();
    l.print();
}
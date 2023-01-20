#include <iostream>
#include <stack>
using namespace std;
void insertatBottom(stack<char>&s,char c){
    if(s.empty()){
        s.push(c);
        return;
    }
    char temp=s.top();
    s.pop();
 
 insertatBottom(s,c);
   s.push(temp);

}
void Reverse(stack<char>&s){
    if(s.empty()){
        return;
    }
    char temp=s.top();
    s.pop();
 
   Reverse(s);
   insertatBottom(s,temp);

}
int main()
{
    stack<char> s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');
    Reverse(s);
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
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
int main()
{
    stack<char> s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');
    insertatBottom(s,'H');
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
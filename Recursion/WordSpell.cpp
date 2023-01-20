#include <bits/stdc++.h>
using namespace std;
string spell[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void WordSpell(int n){
    if(n==0){
        return;
    }
    int lastDig=n%10;
    WordSpell(n/10);
    cout<<spell[lastDig]<<" ";
}
int main(){
    int n;
    cin>>n;
    WordSpell(n);
}
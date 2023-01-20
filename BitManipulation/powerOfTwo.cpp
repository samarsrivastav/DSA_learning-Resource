#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool ans=false;
    if(n&1){
       ans=false;
    }
    else if((n/2)&(n/2 -1)==0){
        ans=true;
    }
    else if(n==0){
        ans=false;
    }


    if(ans)cout<<"YEs"<<endl;
    else{
        cout<<"No"<<endl;
    }
}
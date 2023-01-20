#include<bits/stdc++.h>
using namespace std;
int Power(int a,int b){
   if(b==0){
    return 1;
   }
   int ans=Power(a,b/2)*Power(a,b/2);
   if(b&1){
    ans*=a;
   }
   return ans;
}

int main(){
    cout<<Power(2,1)<<endl;
}
#include <bits/stdc++.h>
using namespace std;

void sum(int *arr,int n){
   int ans=0,s=0,m=-999999;
   for (int i = 0; i < n; i++)
   {
     if(s+arr[i]<0){
        ans=max(ans,s);
        s=0;
        }
     else{
       s+=arr[i];
      ans=max(ans,s);
       
     }
     m=max(m,arr[i]);
   }
   //modification
   if (ans==0)
   {
    ans=m;
    
   }
   
    cout<<"Max is: "<<ans<<endl;
}
int main(){
    int arr[5]={1,2,3,-2,5};
    sum(arr,5);

}
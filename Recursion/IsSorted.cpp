#include<bits/stdc++.h>
using namespace std;
bool sorted(int arr[],int n){
  if(n==1 or n==0){
    return true;
  }
 if(arr[0]<arr[1] && sorted(arr+1,n-1)){
    return true;
 }
 return false;
}
int main(){

    int arr[5]={1,2,3,40,5};
    bool flag=sorted(arr,5);
    if(flag){
        cout<<"YEs"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
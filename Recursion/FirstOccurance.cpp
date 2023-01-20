#include <bits/stdc++.h>
using namespace std;
int FirstOccur(int arr[],int n,int key){
    if(n==0)return -1;
    if(arr[0]==key)return 0;

    int s=FirstOccur(arr+1,n-1,key);
    if(s!=-1){
        return s+1;
    }
    return -1;
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<FirstOccur(arr,5,3)<<endl;
}
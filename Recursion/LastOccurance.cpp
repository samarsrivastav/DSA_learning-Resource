#include <bits/stdc++.h>
using namespace std;
int LastOccur(int arr[],int n,int key){
    if(n==0)return -1;
    if(arr[n-1]==key)return 0;

    int s=LastOccur(arr,n-1,key);
    if(s!=-1){
        return n-(s+1);
    }
    return -1;
}
int main(){
    int arr[6]={1,2,3,4,4,5};
    cout<<LastOccur(arr,6,4)<<endl;
}
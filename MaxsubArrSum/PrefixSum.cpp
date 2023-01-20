#include <iostream>
using namespace std;

void sum(int *arr,int n){
    int s=0,ans=-9999999;
    int prefix[10000]={};
    prefix[0]=arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i]=prefix[i-1]+arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
                s=i>0 ? prefix[j]-prefix[i-1]:prefix[j];
            
            ans=max(ans,s);
        }
    }
    cout<<"Max is: "<<ans<<endl;
}
int main(){
    int arr[5]={1,2,3,4,5};
    sum(arr,5);

}
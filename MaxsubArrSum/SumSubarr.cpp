#include <iostream>
using namespace std;

void sum(int *arr,int n){
    int s=0,ans=-9999999;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            s=0;
            for(int k=i;k<=j;k++){
                s+=arr[k];
            }
            cout<<s<<" ";
            ans=max(ans,s);
        }
        cout<<endl;
        
    }
    cout<<"Max is: "<<ans<<endl;
}
int main(){
    int arr[5]={1,2,3,4,5};
    sum(arr,5);

}
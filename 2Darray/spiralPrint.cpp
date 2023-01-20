#include<bits/stdc++.h>
using namespace std;
void print(int arr[][10],int n,int m){
int sc=0,sr=0,er=n-1,ec=m-1;
while(sc<=ec && sr<=er){

for(int i=sc;i<=ec;i++){
    cout<<arr[sr][i]<<" ";
}
for(int i=sr+1;i<=er;i++){
    cout<<arr[i][ec]<<" ";
}
for(int i=ec-1;i>=sc;i--){
    if(sr==er){ //to avoid double printing of last row
        break;
    }
    cout<<arr[er][i]<<" ";
}
for(int i=er-1;i>=sr+1;i--){
    if(sc==ec){  //to avoid double printing of last col
        break;
    }
    cout<<arr[i][sc]<<" ";
}
sr++;
sc++;
er--;
ec--;

}
}
int main(){
    int arr[][10]={
        {1,2,3,4,5,3},
        {4,5,6,4,5,6},
        {7,8,9,2,4,5}
    };
    print(arr,3,6);
}
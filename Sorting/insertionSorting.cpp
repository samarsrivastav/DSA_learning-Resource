#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector <int> v){

for(int i=1;i<=v.size()-1;i++){
    int current=v[i];
    int prev=i-1;
    while(prev>=0 and current < v[prev]){
       v[prev+1]=v[prev];
       prev=prev-1;
    }
    v[prev+1]=current;
}

}
int main(){
    vector<int>v ={1,2,1,-1,4};
    insertionSort(v);
    for(auto x : v){
        cout<<x<<",";
    }
}
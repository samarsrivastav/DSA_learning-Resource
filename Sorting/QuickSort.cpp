#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v, int s, int e)
{
    int pivot= v[e];
    int i=s-1;
    for(int j=s;j<=e;j++){
        if(v[j]<pivot){
           i++;
           swap(v[i],v[j]);
            
        }
    }
    swap(v[i+1],v[e]);
    return i+1;
}
void QuickSort(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p= Partition(v, s, e);
    QuickSort(v, s, p-1);
    QuickSort(v, p + 1, e);
}

int main()
{
    vector<int> v = {10, 2143, 133, 234, 1};
    int s=0,e=v.size()-1;
    QuickSort(v, s, e);
    for (auto x : v)
    {
        cout << x << ", ";
    }
}
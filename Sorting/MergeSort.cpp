#include <bits/stdc++.h>
using namespace std;
void Merge(vector<int> &v, int s, int e)
{
    int mid = s + (e - s) / 2;
    vector<int> temp;
    int i = s, j = mid + 1;
    while (i <= mid and j <= e)
    {
        if (v[i] < v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    int k = 0;
    while (i <= mid)
    {
        temp.push_back(v[i++]);
    }
    while (j <= e)
    {
        temp.push_back(v[j++]);
    }
    for (int x = s; x <= e; x++)
    {
        v[x] = temp[k];
        k++;
    }
    return;
}
void MergeSort(vector<int> &v, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;

    MergeSort(v, s, mid);
    MergeSort(v, mid + 1, e);

    return Merge(v, s, e);
}

int main()
{
    vector<int> v = {10, 2143, 133, 234, 1};
    int s=0,e=v.size()-1;
    MergeSort(v, s,e);
    for (auto x : v)
    {
        cout << x << ", ";
    }
}
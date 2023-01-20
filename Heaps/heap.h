#include <vector>
using namespace std;
class Heap{
    vector<int>v;
    void Heapify(int i){
        int minidx=i;
        int left=2*i;
        int right=2*i+1;
        if(left<v.size() and v[left]<v[i]){
             minidx=left;
        }
        if(right<v.size() and v[right]<v[minidx]){
             minidx=right;
        }
        if(minidx!=i){
            swap(v[i],v[minidx]);
            Heapify(minidx);
        }
    }
    public:
      Heap(int default_size=10){
        v.reserve(default_size+1);
        v.push_back(-1);
      };
      void insert(int data){
        v.push_back(data);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 and v[idx]<v[parent]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent/=2;
        }
      }
      int top(){
            return v[1];
      }
      void pop(){
        int n=v.size()-1;
        swap(v[1],v[n]);
        v.pop_back();
        Heapify(1);
      }
      bool empty(){
        return v.size()==1;
      }
};
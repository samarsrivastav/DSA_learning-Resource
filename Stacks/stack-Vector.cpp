#include <vector>
using namespace std;

template <typename t>
class stack{
    vector<t> v;
    public:
    void pop(){
        v.pop_back();
    }
    void push(t data){
        v.push_back(data);
    }
    t top(){
        return v[v.size()-1];
    }
    bool empty(){
       return v.size()==0;
    }
};
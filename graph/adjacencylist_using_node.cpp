#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    string name;
    list<string>nbrs;
    node(string name){
        this->name=name;
    }

};
class Graph{
    map<string,node*>m;
    public:
    Graph(vector<string> cities){
        for(auto city:cities){
          m[city]=new node(city);  
        }
    }
   void addEdge(string x,string y,bool undir=false){
     m[x]->nbrs.push_back(y);
    if(undir){
     m[y]->nbrs.push_back(x);
    }
   }
   void print(){
    for(auto x:m){
        node* Node=x.second;
        cout<<x.first<<"-->";
        for(auto nbr:Node->nbrs){
            cout<<nbr<<",";
        }
        cout<<endl;
    }
   }
}; 
int main(){
    vector<string> cities = {"Delhi","London","Paris","New York"};
	Graph g(cities);

	g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New York");

	g.print();
	

	return 0;
}
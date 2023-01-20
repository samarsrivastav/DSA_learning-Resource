#include <bits/stdc++.h>
using namespace std;
class Product{
int id;
char name[100];
int mrp;
int selling_price;

public:
   //setters
   void setMrp(int price){
    mrp=price;
   }
   void setSellingPrice(int price){
    if(price>mrp){
       selling_price=mrp;
    }
    else{
        selling_price=price;
    }
   }

   //getters
   int getMrp(){
    return mrp;
   }
   int getSellingPrice(){
    return selling_price;
   }
};


int main(){
    Product camera;
    camera.setMrp(100);
    camera.setSellingPrice(18);

    cout<<camera.getMrp()<<" "<<camera.getSellingPrice();
}
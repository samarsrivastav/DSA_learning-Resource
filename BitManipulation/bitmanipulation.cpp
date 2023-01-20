#include <bits/stdc++.h>
using namespace std;
void getIthbit(int &n,int i){
    int mask=(1<<i);
    n=n&mask;
    if(n>1)n=1;
    else{
        n=0;
    }
}
void setIthBit(int &n,int i,int v){
    int mask=(v<<i);
    n=n|mask;
}
void clearIthBit(int &n,int i){
    int mask= ~(1<<i);
    n=n&mask;
}
void clearRangeIthBit(int &n,int i,int j){
    int a=(-1<<j+1);
    int b=(1<<i)-1;
    int mask= a|b;
    n=n&mask;
}
void replaceBit(int &n, int i,int j,int m){
    clearRangeIthBit(n,i,j);
    int mask=m<<i;
    n=n|mask;
}
int countBits(int &n){
    int c=0;
    while(n>0){
        int lBit=n&1;
        c+=lBit;
        n=n>>1;
    }
    return c;
}
int countBitsHack(int &n){
    int ans=0;
    while(n>0){
        n=n & (n-1);
        ans++;
    }
    return ans;
}
int main(){
    int n=15;
    int i=2;
    // getIthbit(n,i);
    // setIthBit(n,i,0);
    // clearIthBit(n,i);
    // clearRangeIthBit(n,i,2);
    // replaceBit(n,1,3,2);
    // cout<<countBits(n)<<endl;
    cout<<countBitsHack(n)<<endl;

    cout<<n<<endl;
}
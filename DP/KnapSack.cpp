#include<bits/stdc++.h>
using namespace std;
int KnapSack(int N,int W,int w[],int p[]){
   if(N==0 or W==0){
    return 0;
   }
   int inc=0,exc=0;
   if(w[N-1]<=W){
    inc=p[N-1]+KnapSack(N-1,W-w[N-1],w,p);
   }
   exc=KnapSack(N-1,W,w,p);
   return max(inc,exc);
}
int KnapSackDP(int N,int W,int w[],int p[]){
   vector<vector<int>>dp(N+1,vector<int>(W+1,0));
   for(int i=1;i<=N;i++){
    for(int j=1;j<=W;j++){
        int inc=0,exc=0;
        if(w[i-1]<=W){
            inc=p[i-1]+dp[i-1][j-w[i-1]];
        }
        exc=dp[i-1][j];
        dp[i][j]=max(inc,exc);
    }
   }
   return dp[N][W];
}
int main(){
    int Weight[1000]={2,4,7,11};
    int Price[1000]={5,20,20,100};
    int n=4,W=11;
    // cout<<KnapSack(n,W,Weight,Price)<<endl;  **RECURSION**
    cout<<KnapSackDP(n,W,Weight,Price)<<endl; //   **DP**
}
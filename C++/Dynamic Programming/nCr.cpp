#include <bits/stdc++.h>
using namespace std;

long long int dp[1000][800]={0};
int perm(int n,int r){
        int m=1e9+7;
    if (r>n) return 0;
    if (r==0)return 1;
    if (n==1)return 1;
    if(dp[n][r]!=0){
        return dp[n][r];  
    }    
    long long a=perm(n-1,r)%m+perm(n-1,r-1)%m;
        return dp[n][r]=a%m;
    }
    int nCr(int n, int r){
        return perm(n,r);
    }
int main(){
    int n, r;
    cout<<"Enter values of n and r:";
    cin>>n>>r;
    
    cout<<nCr(n, r)<<endl;
    return 0;
}
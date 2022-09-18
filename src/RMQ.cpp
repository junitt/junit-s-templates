#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<ctime>
using namespace std;
long long n,m,q,k,ans,len;
int num[100004],C[100004],d[100004][20];
int lowbit(int x){
    return x&-x;
}
int Sum(int i){
    int ret=0;
    while(i>0){
        ret+=C[i];i-=lowbit(i);
    }
    return ret;
}
void Add(int x,int d){
    while(x<=100004){
        C[x]+=d;x+=lowbit(x);
    }
}
void Rmq_ini(){
    for(int i=1;i<=n;i++){
        d[i][0]=num[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
        }
    }
}
int Rmq(int l,int r){
    if(l>r)return 0;
    int k=0;
    while((1<<(k+1))<=r-l+1)k++;
    return max(d[l][k],d[r-(1<<k)+1][k]);
}
int main()
{


    return 0;
}
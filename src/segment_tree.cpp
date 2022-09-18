int const maxn=1e6;
int minv[maxn];
int ql,qr;//我要查询的左边界和右边界
int query(int o,int l,int r){
    int M=l+(r-l)/2,ans=INT64_MAX;//取大取小记得改这里
    if(ql<=l&&qr>=r)return minv[o];//完全在查询区间中
    if(ql<=M)ans=min(ans,query(2*o,l,M));
    if(M<qr)ans=min(ans,query(2*o+1,M+1,r));
    return ans;
}
int p,v;//修改A[p]=v;编号o从1开始
void update(int o,int L,int R){
    int M=L+(R-L)/2;
    if(L==R)minv[o]=v;
    else{
        if(p<=M) update(2*o,L,M);else update(2*o+1,M+1,R);
        minv[o]=min(minv[2*o],minv[2*o+1]);
    }
}
//取较大值的线段树
int ql,qr;//我要查询的左边界和右边界
int query(int o,int l,int r){
    int M=l+(r-l)/2,ans=INT64_MIN;//取大取小记得改这里
    if(ql<=l&&qr>=r)return minv[o];//完全在查询区间中
    if(ql<=M)ans=max(ans,query(2*o,l,M));
    if(M<qr)ans=max(ans,query(2*o+1,M+1,r));
    return ans;
}
int p,v;//修改A[p]=v;编号o从1开始
void update(int o,int L,int R){
    int M=L+(R-L)/2;
    if(L==R)minv[o]=v;
    else{
        if(p<=M) update(2*o,L,M);else update(2*o+1,M+1,R);
        minv[o]=max(minv[2*o],minv[2*o+1]);
    }
}
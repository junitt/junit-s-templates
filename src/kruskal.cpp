int n,m;
int fa[1000005];
struct edge
{
    int u,v,w,id;
}que[1000005];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return fa[x]==x? x:fa[x]=find(fa[x]);}
int kruskal(){
    int ret=0;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        que[i].id=i;
    }
    sort(que+1,que+m+1,cmp);
    for(int i=1;i<=m;i++){
        edge& e=que[i];
        int x=find(e.u),y=find(e.v);
        if(x!=y){
            fa[x]=y;ret+=e.w;
        }
    }
    return ret;
}
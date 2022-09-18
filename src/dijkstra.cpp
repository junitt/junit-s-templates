#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<cstring>
#include <sstream>
#include<queue>
#include<vector>
#include<map>
#include<fstream>
#include<unordered_map>
#include<set>
#include<bitset>
#include<cmath>
using namespace std;
typedef pair<int,int> pii;
struct Edge{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d) {}
};
const int maxn=1e5+5;//节点数目
struct Dijstra{
    int n,m;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool done[maxn];//节点是否已经永久标号
    int d[maxn];
    int p[maxn];//最短路上的一条弧
    void init(int n){
        this->n=n;
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        edges.clear();
    }
    void AddEdge(int from,int to,int dist){
        edges.push_back(Edge(from,to,dist));
        m=edges.size();
        G[from].push_back(m-1);
    }
    void dij(int s){
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<=n;i++){d[i]=INT32_MAX;done[i]=false;}//注意这个距离把0也设置成了无限远
        d[s]=0;
        pq.push(make_pair(0,s));
        while(!pq.empty()){
            pii x=pq.top();pq.pop();
            int u=x.second;
            if(done[u])continue;
            done[u]=true;
            for(auto& kk:G[u]){
                Edge& e=edges[kk];
                if(d[e.to]>d[e.from]+e.dist){
                    d[e.to]=d[e.from]+e.dist;
                    p[e.to]=kk;
                    pq.push(make_pair(d[e.to],e.to));
                }
            }
        }
    }   
}dj;
#include <cstdio>
#include <iostream>
#include <cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define int long long
#define maxn 1000
int in[maxn],vis[maxn],num[maxn];
vector<int> v[maxn];
int n;
void toposort(){
    int tot=0;
    queue<int> q;
    for(int i=1;i<=n;i++){if(in[i]==0)q.push(i);}
    while(!q.empty()){
        int kk=q.front();
        q.pop();
        num[++tot]=kk;
        for(auto& u:v[kk]){
            in[u]--;
            if(in[u]==0){
                q.push(u);
            }
        }
    }
}
signed main()
{
    int m;
    while(cin>>n>>m&&n){
        
        for(int i=1;i<=n;i++){
            vis[i]=0;in[i]=0;v[i].clear();
        }
        int x,y;
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            v[x].push_back(y);
            in[y]++;
        }
        toposort();
        for(int i=1;i<=n;i++){
            printf("%lld",num[i]);//注意输出的是longlong类型
            if(i<n)printf(" ");
            else cout<<endl;
        }
    }
    //system("pause");
    return 0;
}
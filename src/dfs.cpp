#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<fstream>
#include<set>
using namespace std;
#define int long long//要开 long long！
//typedef pair<int,int> pii;
//set<pii> tt;
int n,k,m,sm;
int b[500005],ans[500005],r[500005],vis[500005],d[500005];
vector<int> vt[500005],rt[500005];
int dfs(int k,int fa){
	sz[k]=1;
	for(int i=0;i<rt[k].size();i++){
		int u=rt[k][i];
		if(u!=fa){
			sz[k]+=dfs(u,k);
		}
	}

	return sz[k];
}
signed main()
{	
	//outfile.open("afile.txt");
	int a,b;
	for(int i=1;i<=n;i++){rt[i].clear();vis[i]=0;}
	for(int i=1;i<n;i++){
		a=read();b=read();
		rt[a].push_back(b);
		rt[b].push_back(a);
	}
	system("pause");
	return 0;
}

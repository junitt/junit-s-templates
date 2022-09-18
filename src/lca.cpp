#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
struct node{
    int st,ed,len=0;
};
vector<int> rec;
vector<node> unit;
int n,q,p,k;
char line[500002];
bool P(int x,int des){
    if(unit[x].st<=des) return true;
    else return false;
}
int find(int x){
    int ans=-1;
    int l=0,r=unit.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(P(mid,x)) {ans=mid;l=mid+1;}
        else r=mid-1;
    }
    return ans;//l在最小单元左时返回-1
}
void ST_create(){//构造ST
    p=18;F[1][0]=0;F[0][0]=0;
	for(int j=1;j<=p;j++)
		for(int i=1;i<=n;i++)//i先走2^(j-1)步到达F[i][j-1]，再走2^(j-1)步
			F[i][j]=F[F[i][j-1]][j-1];
}

int LCA_st_query(int x,int y) {//求x、y的最近公共祖先
	if(d[x]>d[y])//保证x的深度小于或等于y
		swap(x,y);
	for(int i=p;i>=0;i--)//y向上走到与x同一深度
		if(d[F[y][i]]>=d[x])
			y=F[y][i];
	if(x==y)
		return x;
	for(int i=p;i>=0;i--)//x、y一起向上走
		if(F[x][i]!=F[y][i])
			x=F[x][i],y=F[y][i];
	return F[x][0];//返回x的父节点
}
int main(){
    cin>>n>>q;
    int flag=-1;
    for(int i=1;i<=n;i++){
        cin>>line[i];
        if((line[i]=='1'&&line[i-1]=='0')||(i==1&&line[i]=='1')) {unit.push_back({i,i,0});flag=0;}
        else if(line[i]==line[i-1])unit[unit.size()-1].ed=i;
        else if(line[i]=='0'&&line[i-1]=='1') unit[unit.size()-1].ed=i;
        if(line[i]=='1'){
            unit[unit.size()-1].len++;
        }
        else{
            if(flag==0){
                flag=1;
                unit[unit.size()-1].len++;
            }
        }
    }
    
    int l,r,s1,s2,ans=0;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        if(unit.size()==0) cout<<-1<<endl;continue;
        ans=0;flag=-1;
        int l_pos=find(l),r_pos=find(r);
        for(int j=l;j<min(unit[l_pos+1].st,r);j++){
            if(line[j]=='1') {ans++;flag=0;}
            else{
                if(flag==0){
                    flag=1;
                    ans++;
                }
            }
        }
        for(int j=l_pos+1;j<r_pos;j++){
            ans+=unit[j].len;
        }
        if(r_pos!=-1) 
        {
            flag=-1;
            for(int j=max(unit[r_pos].st,l);j<=r;j++){
            if(line[j]=='1') {ans++;flag=0;}
            else{
                if(flag==0){
                    flag=1;
                    ans++;
                }
            }
        }}
        if(ans!=0)
        cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    system("pause");
	return 0;
}
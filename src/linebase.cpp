#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
ofstream outfile;
int n,num[12],ans,que[15][12],tar_uni,max_d;
void add(long long x)
{
    for(int i=62;i>=0;i--)
    {
        if(x&(1ll<<i))//注意，如果i大于31，前面的1的后面一定要加ll
        {
            if(d[i])x^=d[i];
            else
            {
                d[i]=x;
                break;//插入成功就退出
            }
        }
    }
}
int main()
{
    //outfile.open("afile.txt");
    int r=0;
    while(cin>>n){
        if(n==0)break;
        r++;
        vis.clear();
        for(int i=0;i<n;i++){
            cin>>num[i];
            que[0][i]=num[i];
        }
        num[n]=n+1;que[0][n]=n+1;
        tar_uni=0;
        for(int i=1;i<=n;i++){
            tar_uni*=n;tar_uni+=i-1;
        }
        max_d=0;ans=-1;
        while(1){
            bool ok=dfs(0);
            if(ans!=-1)break;
            max_d++;
        }
        printf("Case %d: %d\n",r,max_d);
        //outfile<<"Case "<<r<<": "<<max_d<<endl;
    }
    system("pause");
	return 0;
}
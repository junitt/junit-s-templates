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
#define int long long//要开 long long！
int m,k,cnt;
long long ans,n;
int num[1000005];
const int MOD=998244353;
inline int read()
{
	int x = 0, ch = '~', fh = 1;
	while (!(ch >= '0' && ch <= '9')) fh = ch == '-' ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1), x += ch - '0', ch = getchar();
	return x * fh;
}
int S[1000005];
void pre(){
	S[0]=0;
	for(int i=1;i<=n;i++){
		S[i]=S[i-1]+num[i];
	}
}
signed main(){
    //outfile.open("afile.txt");
	int T=1;
    //cin>>T;
	bool ok=true;//总共需要20位
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			num[i]=read();
		}
		for(int i=1;i<=n;i++){
            printf("%lld",num[i]);//注意输出的是longlong类型
            if(i<n)printf(" ");
            else cout<<endl;
        }
        //cout << (ok ? "Yes" : "No") << '\n';
    }
	return 0;
}
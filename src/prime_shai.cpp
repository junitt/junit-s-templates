#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int primes[N],cnt;
bool st[N];//primes从0号下标开始
void get_primes(int m){
    if(m==1)cnt=0;
	for(int i=2;i<=m;i++)
	{
		if(!st[i])
		{
			primes[cnt++]=i;
			for(int j=i*2;j<=m;j+=i)st[j]=1;
		}
	}
}
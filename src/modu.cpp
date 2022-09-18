const int MOD=998244353;
inline int read()
{
	int x = 0, ch = '~', fh = 1;
	while (!(ch >= '0' && ch <= '9')) fh = ch == '-' ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1), x += ch - '0', ch = getchar();
	return x * fh;
}
long long poww(long long x,int y)
{
	long long ret=1;
	while(y)
	{
		if(y&1)ret*=x,ret%=MOD;
		x*=x,x%=MOD;
		y>>=1;
	}
	return ret;
}
struct modint
{
	int v;
	modint(){v=0;}
	//modint(int x){v=x%MOD;}
	modint(long long x){v=x%MOD;}
	modint operator+(const modint &a)const{return modint((v+a.v)%MOD);}
	modint operator+=(const modint &a){return *this=*this+a;}
	modint operator-(const modint &a)const{return modint((v-a.v+MOD)%MOD);}
	modint operator-=(const modint &a){return *this=*this-a;}
	modint operator*(const modint &a)const{return modint(1ll*v*a.v);}
	modint operator*=(const modint &a){return *this=*this*a;}
	modint operator/(const modint &a)const{return modint(1ll*v*poww(a.v,MOD-2));}
	modint operator/=(const modint &a){return *this=*this/a;}
	bool operator==(const modint &a)const{return v==a.v;}
}one(1);
modint fac[111110],ifac[111110];
modint C(int n,int m)
{
	return fac[n]*ifac[m]*ifac[n-m];
}
modint dp[77][77][3333];
int main()
{
	int nn;
	//ios_base::sync_with_stdio(false);
	fac[0]=one;
	for(int i=1;i<=110000;i++)fac[i]=fac[i-1]*i;
	ifac[110000]=one/fac[110000];
	for(int i=110000;i>=1;i--)ifac[i-1]=ifac[i]*i;
    return 0;
}
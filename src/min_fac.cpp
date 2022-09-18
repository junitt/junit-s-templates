#define LL long long
const int MAXK=15;
const long long INF=1e18;
int PK=10,Prime[MAXK]={0,2,3,5,7,11,13,17,19,23,29};
//此行数对于long long范围内的素性测试已够用了
long long N;
LL Add(LL x,LL y,LL p){
	if(x+y<p)return x+y;
	return x+y-p;
}
LL gcd(LL x,LL y){//最大公因数
	if(x==0)return y;
	return gcd(y%x,x);
}
LL quick_Mul(LL x,LL y,LL p){//龟速乘
	x%=p;y%=p;
	LL ret=0;
	while(y){
		if(y&1)ret=Add(ret,x,p);
		x=Add(x,x,p);
		y>>=1;
	}
	return ret;
}
LL quick_Pow(LL x,LL y,LL p){//快速幂
	LL ret=1;
	while(y){
		if(y&1)ret=quick_Mul(ret,x,p);
		x=quick_Mul(x,x,p);
		y>>=1;
	}
	return ret;
}
int MillerTest(LL N){//素数测试
	if(N<=1||N==4)return 0;
	if(N<=3)return 1;
	LL D=N-1;
	while(D%2==0)D/=2;
	for(int i=1;i<=PK;i++){
		if(Prime[i]>=N)return 1;
		int Ok=0;
		LL A=Prime[i];
		LL x=quick_Pow(A,D,N);
		if(x==1||x==N-1)
			continue;
		while(D!=N-1){
			x=quick_Mul(x,x,N);
			D*=2;
			if(x==1)return 0;
			if(x==N-1){Ok=1;break;}
		}
		if(!Ok)return 0;
	}
	return 1;
}
LL PollardRho(LL N){//找因数
	if(N==1)return -1;
	for(int i=1;i<=PK;i++)
		if(N%Prime[i]==0)
			return Prime[i];//特判出奇迹
	LL x=(rand()%(N-2))+2,y=x;
	LL P=(rand()%(N-1))+1,D=1;
	while(D==1){
		x=(quick_Mul(x,x,N)+P)%N;
		y=(quick_Mul(y,y,N)+P)%N,y=(quick_Mul(y,y,N)+P)%N;
		D=gcd(abs(x-y),N);
	}
	return D;
}
LL Min_Div(LL N){//最小质因数
	if(N==1)return INF;
	if(MillerTest(N))return N;
	LL X=PollardRho(N);
	return min(Min_Div(X),Min_Div(N/X));
}

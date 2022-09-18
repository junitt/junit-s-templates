#include<bits/stdc++.h>
#define Reg register
#define RI Reg int
#define RL Reg LL
#define Con const
#define CI Con int&
#define CL Con LL&
#define I inline
#define W while
#define LL long long
#define Gmax(x,y) (x<(y)&&(x=(y)))
#define abs(x) ((x)<0?-(x):(x))
#define hl_AK_NOI true
using namespace std;
I LL Qmul(CL x,CL y,CL X)//快速乘
{
    RL k=(LL)((1.0L*x*y)/(1.0L*X)),t=x*y-k*X;
    t-=X;W(t<0) t+=X;return t;
}
class MillerRabin//MillerRabin判素数板子
{
    private:
        #define Pcnt 12
        Con int P[Pcnt]={2,3,5,7,11,13,17,19,61,2333,4567,24251};
        I LL Qpow(RL x,RL y,CL X)
        {
            RL t=1;W(y) y&1&&(t=Qmul(t,x,X)),x=Qmul(x,x,X),y>>=1;
            return t;
        }
        I bool Check(CL x,CI p)
        {
            if(!(x%p)||Qpow(p%x,x-1,x)^1) return false;
            RL k=x-1,t;W(!(k&1))
            {
                if((t=Qpow(p%x,k>>=1,x))^1&&t^(x-1)) return false;
                if(!(t^(x-1))) return true;
            }return true;
        }
    public:
        bool IsPrime(CL x)
        {
            if(x<2) return false;
            for(RI i=0;i^Pcnt;++i) {if(!(x^P[i])) return true;if(!Check(x,P[i])) return false;}
            return true;
        }
};
class PollardRho//PollardRho分解质因数
{
    private:
        #define Rand(x) (1LL*rand()*rand()*rand()*rand()%(x)+1)
        LL ans;MillerRabin MR;
        I LL gcd(CL x,CL y) {return y?gcd(y,x%y):x;}//求gcd
        I LL Work(CL x,CI y)//分解
        {
            RI t=0,k=1;RL v0=Rand(x-1),v=v0,d,s=1;W(hl_AK_NOI)//初始化随机一个v0
            {
                if(v=(Qmul(v,v,x)+y)%x,s=Qmul(s,abs(v-v0),x),!(v^v0)||!s) return x;//计算当前v，统计乘积，判断是否分解失败
                if(++t==k) {if((d=gcd(s,x))^1) return d;v0=v,k<<=1;}//倍增
            }
        }
        I void Resolve(RL x,RI t)//分解
        {
            if(!(x^1)||x<=ans) return;if(MR.IsPrime(x)) return (void)Gmax(ans,x);//先进行特判
            RL y=x;W((y=Work(x,t--))==x);W(!(x%y)) x/=y;Resolve(x,t),Resolve(y,t);//找到一个因数y，然后分解（注意除尽）
        }
    public:
        I PollardRho() {srand(20050521);}//初始化随机种子
        I LL GetMax(CL x) {return ans=0,Resolve(x,302627441),ans;}//求最大的质因数
}P;//效率n^1/4
int num[1000005],cpy[1000005];
void getpm(int n){
    int pm,cnt=0;
    pm=P.GetMax(n);
    n/=pm;
    cpy[++cnt]=pm;
    while(1){
        if(n==1)break;
        pm=P.GetMax(n);
        cpy[++cnt]=pm;
        n/=pm;
    }
    num[0]=cnt;
    for(int i=1;i<=cnt;i++){
        num[i]=cpy[cnt-i+1];
    }
}
void prime_factors(int n, vector<int>& primes)
{
    int m = floor(sqrt(n)+0.5);
    for (int i = 2;i<=m;++i)
        if (n % i==0)
        {
            primes.push_back(i);
            while (n % i == 0) n/=i;
        }
    if (n > 1) primes.push_back(n);
}
signed main(){
    int n,q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {cin>>n;
    getpm(n);
    for(int i=1;i<=num[0];i++){
        cout<<num[i]<<endl;
    }}
    return 0;
}
int gcd(int a, int b)
{ return b == 0 ? a : gcd(b, a % b); }//求余数到求不了为止，大的在左边当被除数
void exgcd(int a,int b,int& d,int& x,int& y){
    if(b==0){d=a;x=1;y=0;}
    else{
        gcd(b,a%b,d,y,x);y-=x*(a/b);
    }
}
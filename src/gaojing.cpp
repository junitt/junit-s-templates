void multi(int *a,int *b,int *c){//c是最后输出到数组
    memset(c,0,sizeof(c));
    const int maxn=500;//要求到第几位
    int pt;
    for(int i=1;i<=maxn;i++){
		for(int j=1;i+j-1<=maxn;j++){
			c[i+j]+=(a[i]*b[j])/10;
			pt=i+j;
			while(pt<=maxn&&c[pt]>=10){
	    		c[pt+1]+=c[pt]/10;
				c[pt]%=10;
				pt++;
			}
			c[i+j-1]+=(a[i]*b[j])%10;
			pt=i+j-1;
			while(pt<=maxn&&c[pt]>=10){
				c[pt+1]+=c[pt]/10;
				c[pt]%=10;
				pt++;
			}
		}
	}
}
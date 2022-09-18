const int INF=1001;//这要求比任何可连接的路更大
int d[1003][1003];
void Floyd(int n){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][k]<INF&&d[k][j]<INF)
                    d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
}
void Floydliantong(int n){//判断有向图两点是否相连
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][k]<INF&&d[k][j]<INF)
                    d[i][j]=(d[i][k]&&d[k][j])||d[i][j];
}
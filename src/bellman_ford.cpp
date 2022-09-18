const int maxn = 1000;

struct Edge
{
    int from,to;
    int dist;
};

struct BellmanFord
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];
    int d[maxn];
    int p[maxn];
    int cnt[maxn];

    void init(int n)
    {
        this->n = n;
        for(int i=0; i<n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int dist)
    {
        edges.push_back((Edge)
        {
            from,to,dist
        });
        m = edges.size();
        G[from].push_back(m-1);
    }

    bool Bellman_Ford(int s)
    {
        queue<int> Q;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<n; i++)
        {
            d[i] = INF;
        }

        d[s] = 0;
        inq[s] = true;
        Q.push(s);

        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inq[u] = false;
            for(int i=0; i<G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if(d[u]<INF&&d[e.to]>d[u]+e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    if(!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to] = true;
                        if(++cnt[e.to]>n)
                            return false;
                    }
                }
            }
        }
        return true;
    }

};
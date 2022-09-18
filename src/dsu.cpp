int fa[1000005];
int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }
void join(int x, int y)
{
	x = gf(x);
	y = gf(y);
	if (x == y)
		return;
	fa[x] = y;
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(x); }
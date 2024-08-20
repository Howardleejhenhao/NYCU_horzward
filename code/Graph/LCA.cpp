vector<int> a[N];
int dep[N], lif[N][20];

void dfs(int x, int p)
{
    dep[x] = dep[p] + 1;
    for(int i: a[x])
        if(i != p)
            dfs(i, x);
}

void init(int n)
{
    dfs(1, 0);
    for(int i=1; (1<<i)<n; i++)
        for(int j=1; j<=n; j++)
            lif[j][i] = lif[lif[j][i-1]][i-1];
}

int up(int x, int k)
{
    int j = 0;
    while(k)
    {
        if(k & 1)
            x = lif[x][j];
        k /= 2, j++;
    }
    return x;
}

int lca(int x, int y, int n)
{
    if(dep[x] > dep[y])
        swap(x, y);
    y = up(y, dep[y] - dep[x]);
    if(x == y)
        return x;
    for(int i=__lg(n); i>=0; i--)
    {
        if(lif[x][i] != lif[y][i])
            x = lif[x][i], y = lif[y][i];
    }
    return lif[x][0];
}

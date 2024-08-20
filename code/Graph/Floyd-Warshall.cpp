const int N = 505;
const long long INF = 0x3f3f3f3f3f3f3f3f;
 
long long dis[N][N];
 
int main()
{
    memset(dis, 0x3f, sizeof(dis));
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++)
        dis[i][i] = 0LL;
    for(int i=0, x, y, z; i<m; i++)
    {
        cin >> x >> y >> z;
        dis[x][y] = min(dis[x][y], 1LL * z);
        dis[y][x] = min(dis[y][x], 1LL * z);
    }
 
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
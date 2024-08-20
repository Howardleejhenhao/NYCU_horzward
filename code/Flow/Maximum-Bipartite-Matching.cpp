// add dinic
// 左邊有 n 個點，右邊有 m 個點，共有 e 條邊
void solve()
{
    int n, m, e;
    cin >> n >> m >> e;
    flow.init(n + m + 10, n + m + 1, n + m + 2);
    while(e--) {
        int a, b;
        cin >> a >> b;
        flow.add_edge(a, b + n, 1);
    }
    for(int i = 1; i <= n; i++) {
        flow.add_edge(n + m + 1, i, 1);
    }
    for(int i = n + 1; i <= n + m; i++) {
        flow.add_edge(i, n + m + 2, 1);
    }
    cout << flow.flow() << '\n';
    return;
}
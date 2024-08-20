// add dinic
// 給定兩個點 start 和 end ， 中間會有很多條路，問你說最小要刪除幾條路才可以保證 start 不能到 end
vector<pair<int, int>> ans;
vector<int> vis(MXN);

void dfs(int x)
{
    vis[x] = 1;
    for(auto i : flow.ed[x]) {
        if(vis[i.v] == 1) continue;
        if(vis[i.v] == 0 && i.f > 0) {
            dfs(i.v);
        }
    }
}
vector<pair<int, int>> G;
void solve()
{
    int n, m;
    cin >> n >> m;
    flow.init(n + 1, 1, n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        flow.add_edge(a, b, 1);
        flow.add_edge(b, a, 1);
        G.push_back({a, b});
        // flow.add_edge(b, a, 1);
    }
    flow.flow();
    dfs(1);
    for(pair<int, int> i : G) {
        if((vis[i.first] == 1 && vis[i.second] == 0) || (vis[i.first] == 0 && vis[i.second] == 1)) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto i : ans) {
        cout << i.first << ' ' << i.second << '\n';
    }

    return;
}
const int N = 4e4 + 10;

// add segment tree

vector<int> ed[N];
int sz[N], dep[N], son[N], fa[N];
void dfs_sz(int x, int f, int d){ //當前節點 x ，父節點 f，深度 d
    sz[x] = 1;    dep[x] = d;    fa[x] = f;
    for(int i : ed[x]){
        if(i == f)    continue;
        dfs_sz(i, x, d+1);
        sz[x] += sz[i];
        if(sz[son[x]] < sz[i])    son[x] = i;
    }
}

int top[N]; // 維護每個節點所在的鏈的頂端節點
int dfn[N], rnk[N]; // dfn -> node to seg, rnk -> tree to node
int cnt = 1; // index start from 1
void dfs_hld(int x, int f){
    top[x] = (son[fa[x]] == x ? top[fa[x]] : x);
    rnk[cnt] = x;
    dfn[x] = cnt++;
    if(son[x])    dfs_hld(son[x], x);
    for(int i : ed[x]){
        if(i == f || i == son[x])    continue;
        dfs_hld(i, x);
    }
}

int getSum(int u, int v) {
    int ret = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] > dep[top[v]]) {
            int a = dfn[top[u]], b = dfn[u];
            if(a > b) swap(a, b);
            ret += segsum.query(1, n, 1, a, b);
            u = fa[top[u]];
        }
        else {
            int a = dfn[top[v]], b = dfn[v];
            if(a > b) swap(a, b);
            ret += segsum.query(1, n, 1, a, b);
            v = fa[top[v]];
        }
    }
    if(dfn[u] < dfn[v]) {
        ret += segsum.query(1, n, 1, dfn[u], dfn[v]);
    }
    else {
        ret += segsum.query(1, n, 1, dfn[v], dfn[u]);

    }
    return ret;
}

int getMax(int u, int v) {
    int ret = -1e15;
    while(top[u] != top[v]){
        if(dep[top[u]] > dep[top[v]]) {
            int a = dfn[top[u]], b = dfn[u];
            if(a > b) swap(a, b);
            ret = max(ret, segmax.query(1, n, 1, a, b));
            u = fa[top[u]];
        }
        else {
            int a = dfn[top[v]], b = dfn[v];
            if(a > b) swap(a, b);
            ret = max(ret, segmax.query(1, n, 1, a, b));
            v = fa[top[v]];
        }
    }
    if(dfn[u] < dfn[v]) {
        ret = max(ret, segmax.query(1, n, 1, dfn[u], dfn[v]));
    }
    else {
        ret = max(ret, segmax.query(1, n, 1, dfn[v], dfn[u]));

    }
    return ret;
}

int getLca(int u, int v) {
    while(top[u] != top[v]){
        if(dep[top[u]] > dep[top[v]])
            u = fa[top[u]];
        else
            v = fa[top[v]];
    }
    return dep[u] > dep[v] ? v : u;
}

void solve()
{
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs_sz(1, 1, 0);
    dfs_hld(1, 1);
    vector<int> w(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> w[dfn[i]];
    }
    segmax.init(1, n, 1, w);
    segsum.init(1, n, 1, w);
    int q;
    cin >> q;
    while(q--) {
        string op;
        cin >> op;
        if(op == "QMAX") {
            int a, b;
            cin >> a >> b;
            cout << getMax(a, b) << '\n';
        }
        else if(op == "QSUM") {
            int a, b;
            cin >> a >> b;
            cout << getSum(a, b) << '\n';
        }
        else {
            int a, t;
            cin >> a >> t;
            segmax.update(1, n, 1, dfn[a], t);
            segsum.update(1, n, 1, dfn[a], t);
        }
    }
    return;
}
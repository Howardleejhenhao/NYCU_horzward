const int MAXN = 1e6 + 10;
int X[MAXN << 1];
struct scanline {
    int x, down, up, mark;
    bool operator<(const scanline& other) const {
        return x < other.x;
    }
};

vector<scanline> v;
int node[MAXN << 2], lazy[MAXN << 2]; // for segtree

void Push(int idx, int l, int r) {
    if(lazy[idx]) node[idx] = r - l + 1;
    else if(r != l) node[idx] = node[idx * 2] + node[idx * 2 + 1];
    else node[idx] = 0; 
}

void Update(int idx, long long L, long long R, int ul, int ur, int d) { // d -> mark
    if(ul <= L && R <= ur) {
        lazy[idx] += d;
        Push(idx, L, R);
        return;
    }
    int mid = (L + R) / 2;
    if(ul <= mid) Update(idx * 2, L, mid, ul, ur, d);
    if(mid < ur) Update(idx * 2 + 1, mid + 1, R, ul, ur, d);
    Push(idx, L, R);
}
// 給定很多個四邊形，要你求總面積
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        v.push_back({l, d + 1, u, 1});
        v.push_back({r, d + 1, u, -1});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    int last = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(v[i].x != last) {
            ans += (long long)1 * (v[i].x - last) * node[1];
            last = v[i].x;
        }
        Update(1, 1, 1000000, v[i].down, v[i].up, v[i].mark);
    }
    cout << ans << '\n';
    return;
}

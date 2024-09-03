const int N = 210;
const int INF = 1e9 + 7;
struct KM { // max weight, for min negate the weights
    int n, mx[N], my[N], pa[N];
    long long g[N][N], lx[N], ly[N], sy[N];
    bool vx[N], vy[N];
    vector<pair<int, int>> match;
    void init(int _n) { // 1-based
        n = _n;
        for(int i = 1; i <= n; i++) fill(g[i], g[i] + n + 1, 0);
    }
    void addEdge(int x, int y, long long w) {
        g[x][y] = w;
    }
    void augment(int y) {
        for(int x, z; y; y = z) {
            x = pa[y], z = mx[x], my[y] = x, mx[x] = y;
        }
    }
    void bfs(int st) {
        for(int i = 1; i <= n; ++i) sy[i] = INF, vx[i] = vy[i] = 0;
        queue<int> q;
        q.push(st);
        for(;;) {
            while(q.size()) {
                int x=q.front();
                q.pop();
                vx[x] = 1;
                for(int y = 1; y <= n; ++y) {
                    if(!vy[y]){
                        long long t = lx[x] + ly[y] - g[x][y];
                        if(t == 0) {
                            pa[y] = x;
                            if(!my[y]){augment(y);return;}
                            vy[y]=1, q.push(my[y]);
                        }
                        else if(sy[y]>t) pa[y]=x,sy[y]=t;
                    } 
                }
            }
            long long cut = INF;
            for(int y = 1; y <= n; ++y) {
                if(!vy[y] && cut > sy[y]) {
                    cut = sy[y];
                }
            }
            for(int j = 1; j <= n; ++j) {
                if(vx[j]) lx[j] -= cut;
                if(vy[j]) ly[j] += cut;
                else sy[j] -= cut;
            }
            for(int y = 1; y <= n; ++y) {
                if(!vy[y] && sy[y] == 0) {
                    if(!my[y]) {
                        augment(y);
                        return;
                    }
                    vy[y]=1;
                    q.push(my[y]);
                } 
            }
        } 
    }
    long long solve(){
        fill(mx, mx + n + 1, 0); 
        fill(my, my + n + 1, 0);
        fill(ly, ly + n + 1, 0); 
        fill(lx, lx + n + 1, -INF);
        for(int x = 1; x <= n; ++x) {
            for(int y = 1; y <= n; ++y) {
                lx[x] = max(lx[x], g[x][y]);
            }
        }
        for(int x = 1; x <= n; ++x) bfs(x);
        long long ans = 0;
        for(int y = 1; y <= n; ++y) {
            ans += g[my[y]][y];
            match.push_back({my[y], y});
        }
        return ans;
    } 
} graph;
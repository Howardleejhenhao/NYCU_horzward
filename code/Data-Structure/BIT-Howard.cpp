// 一維
struct BIT
{
    // 1~n
    int n;
    int bit_num;
    vector<long long> d;
    void init(int size) {
        n = size;
        bit_num = __lg(size) + 1;
        d.resize(1 << bit_num);
        memset(d.data() + 1, 0, sizeof(long long) * (1 << bit_num));
    }
    BIT(int size) {
        init(size);
    }
    void ins(int x, long long v) {
        for(; x <= n; x += x & -x) {
            d[x] += v;
        }
    }
    long long query(int x) {
        if(x <= 0) {
            return 0;
        }
        long long s = 0;
        for(; x > 0; x -= x & -x) {
            s += d[x];
        }
        return s;
    }
    long long query_range(int x, int y) {
        if(x > y) {
            return 0;
        }
        long long s = query(y);
        if(x) {
            s -= query(x - 1);
        }
        return s;
    }
    long long k_th(int k) {
        int now = 0;
        for(int i = bit_num - 1; i >= 0; i--) {
            if(d[now + (1 << i)] < k) {
                k -= d[now + (1 << i)];
                now += 1 << i;
            }
        }
        return now + 1;
    }
};
// 二維
struct BIT
{
    int n;
    int bit_num;
    vector<vector<int>> d;
    void init(int size) {
        n = size;
        bit_num = __lg(size) + 1;
        d.resize(1 << bit_num);
        int ln = d.size();
        for(int i = 0; i < ln; i++) {
            for(int j = 0; j < ln; j++) {
                d[i].push_back(0);
            }
        }
        // memset(d.data() + 1, 0, sizeof(long long) * (1 << bit_num));
    }
    BIT(int size) {
        init(size);
    }
    void ins(int x, int y, long long v) {
        for(; x <= n; x += x & -x) {
            for(int j = y; j <= n; j += j & -j) {
                d[x][j] += v;
            }
        }
    }
    long long query(int x, int y) {
        long long s = 0;
        for(; x > 0; x -= x & -x) {
            for(int j = y; j > 0; j -= j & -j){
                s += d[x][j];
            }
        }
        return s;
    }
    long long query_range(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
};
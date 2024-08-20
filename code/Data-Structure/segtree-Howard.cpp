using TYPE = int;
const int SIZE = 1 << 19;
// 15:32678 16:65536 17:131072 18:2624144 19:524288 20:1048576
struct segment_tree
{
    // start from 1
    TYPE node[SIZE];
    TYPE merge(TYPE a, TYPE b) {
        return min(a, b);
    }
    void pull(int idx) {
        node[idx] = merge(node[idx * 2], node[idx * 2 + 1]);
    }
    void init(int L, int R, int idx, vector<TYPE> &input) {
        if(L == R) {
            node[idx] = input[L];
            return;
        }
        int now = (L + R) / 2;
        init(L, now, idx * 2, input);
        init(now + 1, R, idx * 2 + 1, input);
        pull(idx);
    }
    TYPE query(int L, int R, int idx, int l, int r) {
        if(L >= l && R <= r) return node[idx];
        int now = (L + R) / 2;
        if(r <= now) return query(L, now, idx * 2, l, r);
        if(l > now) return query(now + 1, R, idx * 2 + 1, l, r);
        return merge(query(L, now, idx * 2, l, r), query(now + 1, R, idx * 2 + 1, l, r));
    }
    void update(int L, int R, int idx, int p, TYPE v) {
        if(L == R) {
            node[idx] = v;
            return;
        }
        int now = (L + R) / 2;
        if(p <= now) update(L, now, idx * 2, p, v);
        else update(now + 1, R, idx * 2 + 1, p, v);
        pull(idx);
    }
};
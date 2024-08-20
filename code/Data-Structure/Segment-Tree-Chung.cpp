struct seg{
    int L,R;
    int data;
    int lson, rson;
    int chg;
    int real(){
        return data + chg;
    };
};
template<typename T>
struct segtree{
    //declare
    const int maxn;
    int stptr = 1;
    vector<seg> ST;

    // constructor
    segtree(const int &sz): maxn(sz) { ST.resize(2*sz); }

    //operation
    void merge(seg &par, seg &lson, seg &rson){
        ;
    }
    seg merge(seg a, seg b){
        seg ret;
        ;
        return ret;
    }
    void push(int idx, int lson, int rson){
        ST[idx].data = ST[idx].real();
        ST[lson].chg += ST[idx].chg;
        ST[rson].chg += ST[idx].chg;
        ST[idx].chg = 0;
    }

    // functions
    void build(int L,int R,int idx,vector<T>& v){
        ST[idx].L = L, ST[idx].R = R;
        if(L + 1 == R){
            ST[idx].data = v[L];
            return;
        }
        int mid = (L+R) / 2;
        int lson = ST[idx].lson = stptr++;
        int rson = ST[idx].rson = stptr++;
        build(L,mid,lson,v);
        build(mid,R,rson,v);
        merge(ST[idx], ST[lson], ST[rson]);
    }
    void single_modify(int pos,int x,int idx){
        if(ST[idx].L + 1 == ST[idx].R){
            ST[idx].data = x;
            return;
        }
        int mid = (ST[idx].L+ST[idx].R) / 2;
        int lson = ST[idx].lson, rson = ST[idx].rson;
        if(pos < mid) single_modify(pos,x,lson);
        else single_modify(pos,x,rson);
        merge(ST[idx], ST[lson], ST[rson]);
    }
    void range_modify(int L,int R,int x,int idx){
        if(ST[idx].L == L && ST[idx].R == R){
            ST[idx].chg += x;
            return;
        }
        int mid = (ST[idx].L + ST[idx].R) / 2;
        int lson = ST[idx].lson, rson = ST[idx].rson;
        push(idx, lson, rson);
        if(R <= mid) range_modify(L,R,x,lson);
        else if(L >= mid) range_modify(L,R,x,rson);
        else range_modify(L,mid,x,lson), range_modify(mid,R,x,rson);
        merge(ST[idx], ST[lson], ST[rson]);
    }
    seg range_query(int L,int R,int idx){
        if(ST[idx].L == L && ST[idx].R == R){
            return ST[idx];
        }
        int mid = (ST[idx].L+ST[idx].R) / 2;
        int lson = ST[idx].lson, rson = ST[idx].rson;
        push(idx, lson, rson);
        if(R <= mid) return range_query(L,R,lson);
        if(L >= mid) return range_query(L,R,rson);
        return merge(range_query(L,mid,lson), range_query(mid,R,rson));
    }
};

int main(){
    const int maxn = 2e5+5;
    int n; cin>>n;
    vector<int> v(n);
    segtree<int> ST(maxn);
    ST.build(0,n,0,v); // [0, n) 
    ST.single_modify(3,10,0); // 在 3 的位置 +10 (0-based)
    ST.range_modify(4,8,5,0); // 在 [4, 8) 的位置 +10 (0-based)
    cout<<ST.range_query(0,n,0).real()<<"\n"; // 查詢 [0, n)
    return 0;
}
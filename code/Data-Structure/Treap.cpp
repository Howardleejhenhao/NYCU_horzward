// string reverse
/*
input
7 2
AYBABTU
3 4
4 7

output
AYAUTBB
*/
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count()); // C++ randomizer
struct Treap
{
    char key;
    int pri, sz, tag;
    Treap *l, *r;
    Treap(char _key) {
        key = _key;
        pri = gen();
        sz = 1;
        tag = 0;
        l = nullptr;
        r = nullptr;
    }
};
 
Treap *root = nullptr;
string s;
 
int Size(Treap *x)
{
    return x ? x -> sz : 0;
}
 
void push(Treap *x)
{
    if(x -> tag) {
        swap(x -> l, x -> r);
        if(x -> l) x -> l -> tag ^= 1;
        if(x -> r) x -> r -> tag ^= 1;
        x -> tag = 0;
    }
}
 
void pull(Treap *x)
{
    x -> sz = Size(x -> l) + Size(x -> r) + 1;
}
 
Treap *merge(Treap *a, Treap *b) 
{
    if(!a || !b) return a ? a : b;
    if(a -> pri > b -> pri) {
        push(a);
        a -> r = merge(a -> r, b);
        pull(a);
        return a;
    }
    else {
        push(b);
        b -> l = merge(a, b -> l);
        pull(b);
        return b;
    }
}
 
void build(int n) // string size
{
    for(int i = 0; i < n; i++) {
        root = merge(root, new Treap(s[i]));
    }
}
 
void splitbykth(Treap *x, int k, Treap *&a, Treap *&b)
{
    if(!x) {
        a = b = nullptr;
        return;
    }
    push(x);
    if(Size(x -> l) + 1 <= k) {
        a = x;
        splitbykth(a -> r, k - Size(x -> l) - 1, a -> r, b);
        pull(a);
    }
    else {
        b = x;
        splitbykth(b -> l, k, a, b -> l);
        pull(b);
    }
}
 
void reverse_update(int a, int b)
{
    Treap *l, *m, *r;
    splitbykth(root, b, l, r);
    splitbykth(l, a - 1, l, m);
    m -> tag = 1;
    root = merge(merge(l, m), r);
}
 
void output(Treap *x)
{
    if(!x) return;
    push(x);
    output(x -> l);
    cout << x -> key;
    output(x -> r);
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    cin >> s;
    build(n);
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        reverse_update(l, r);
    }
    output(root);
    cout << '\n';
    return;
}
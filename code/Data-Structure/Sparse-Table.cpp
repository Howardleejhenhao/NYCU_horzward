int n, q, a[200005], lg_table[200005], sparse_table[19][200005];
 
void init_lg()
{
    for(int i=0, lg=0; i<=n; i++)
    {
        if(i>=(2<<lg))
            lg++;
        lg_table[i] = lg;
    }
}
 
void init_sparse()
{
    for(int i=0; i<n; i++)
        sparse_table[0][i] = a[i];
    for(int k=1; k<=lg_table[n]; k++)
        for(int i=0; i+(1<<k)<=n; i++)
            sparse_table[k][i] = min(sparse_table[k-1][i], sparse_table[k-1][i+(1<<(k-1))]);
}
 
int query_sparse(int l, int r)
{
    int k = lg_table[r-l];
    return min(sparse_table[k][l], sparse_table[k][r-(1<<k)]);
}
 
int main()
{
    cin >> n >> q;
    for(int i=0; i<n; i++)
        cin >> a[i];
    init_lg(), init_sparse();
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << query_sparse(x, y+1) << "\n";
    }
}
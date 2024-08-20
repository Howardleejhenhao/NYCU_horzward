struct SEG
{
    int n;
    int seg[1<<19];
 
    void init(int x)
    {
        n = 1<<(__lg(x) + 1);
    }
 
    void update(int x, int dif)
    {
        x += n;
        seg[x] += dif, x /= 2;
        while(x)
            seg[x] = max(seg[2*x], seg[2*x+1]), x /= 2;
    }
 
    int query(int g)
    {
        if(seg[1] < g)
            return -1;
        int id = 1;
        while(id < n)
        {
            if(seg[2*id] >= g)
                id = 2*id;
            else
                id = 2*id+1;
        }
 
        return id - n;
    }
}bm;
struct segtree
{
    int n;
    long long tg[2][1<<19], seg[1<<19];
    //0: add, 1: set;
 
    void init(int x)
    {
        n = 1<<(__lg(x) + 1);
    }
 
    void set(bool tp, int idx, long long val)
    {
        if(tp == 0)
        {
            (tg[1][idx])? (tg[1][idx] += val): (tg[0][idx] += val);
            seg[idx] += val;
        }
        else
        {
            tg[0][idx] = 0, tg[1][idx] = val, seg[idx] = val;
        }
    }
 
    void push(int idx)
    {
        for(int i=__lg(idx); i>0; i--)
        {
            int now = idx>>i;
            if(tg[0][now])
            {
            	set(0, 2*now, tg[0][now]/2);
            	set(0, 2*now+1, tg[0][now]/2);
            	tg[0][now] = 0;
            }
            if(tg[1][now])
            {
            	set(1, 2*now, tg[1][now]/2);
            	set(1, 2*now+1, tg[1][now]/2);
            	tg[1][now] = 0;
            }
        }
    }
 
    void pull(int idx)
    {
        idx >>= 1;
        while(idx)
        {
        	if(tg[1][idx])
        		seg[idx] = tg[1][idx];
        	else
        		seg[idx] = tg[0][idx] + seg[2*idx] + seg[2*idx+1];
        	idx /= 2;
        }
    }
 
    void update(bool tp, int l, int r, long long val)
    {
        l += n, r += n;
        int tl = l, tr = r-1, len = 1;
        push(l), push(r-1);
        while(l < r)
        {
            if(l & 1)
                set(tp, l++, val*len);
            if(r & 1)
                set(tp, --r, val*len);
            l /= 2, r /= 2, len *= 2;
        }
        pull(tl), pull(tr);
    }
 
    long long query(int l, int r)
    {
        l += n, r += n;
        push(l), push(r-1);
        long long ret = 0;
        while(l < r)
        {
            if(l & 1)
                ret += seg[l++];
            if(r & 1)
                ret += seg[--r];
            l /= 2, r /= 2;
        }
        return ret;
    }
};

void build(string &s)
{
    int n = s.size();
    for(int i=0, v=0; i<n; i++)
    {
        pii &now = a[v][s[i]-'a'];
        if(now.first != -1)
            v = now.first;
        else
            v = now.first = ++idx;
        if(i == n-1)
            now.second++;
    }
}
using pii = pair<int, long long>;
const long long INF = 0x3f3f3f3f3f3f3f3f;
 
vector<pii> a[N];
 
struct cmp
{
    bool operator()(pii x, pii y)
    {
        if(x.second != y.second)
            return x.second > y.second;
        return x.first > y.first;
    }
};
 
long long dis[N];
priority_queue<pii, vector<pii>, cmp> pq;
 
int main()
{
    memset(dis, 0x3f, sizeof(dis));

    for(int i=1; i<=n; i++)
        sort(a[i].begin(), a[i].end(), [](pii x, pii y){return x.second < y.second;});

    dis[1] = 0;
    for(pii i: a[1])
    {
        if(dis[i.first] <= i.second)
            continue;
        pq.push(i);
        dis[i.first] = i.second;
    }

    while(!pq.empty())
    {
        pii now = pq.top();
        pq.pop();
        if(dis[now.first] != now.second)
            continue;
 
        for(pii i: a[now.first])
        {
            long long dis_now = i.second + now.second;
            if(dis[i.first] <= dis_now)
                continue;
            dis[i.first] = dis_now;
            pq.push({i.first, dis[i.first]});
        }
    }
 
    for(int i=1; i<=n; i++)
        cout << dis[i] << " ";
    cout << "\n";
}
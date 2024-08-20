struct EDGE
{
	int first, second;
	long long val;
};
 
vector<EDGE> e;
 
long long dis[N];
int pre[N];
int bellman()
{
	int ret = 0;
	for(EDGE i: e)
	{
		if(dis[i.second] > dis[i.first] + i.val)
		{
			dis[i.second] = dis[i.first] + i.val;
			pre[i.second] = i.first;
			ret = i.second;
		}
	}
	return ret;
}
 
bool vis[N];
void f_neg(int x)
{
	vector<int> ret;
	while(!vis[x])
	{
		vis[x] = 1;
		ret.push_back(x);
		x = pre[x];
	}
	ret.push_back(x);
	reverse(ret.begin(), ret.end());
	while(ret.back() != x)
		ret.pop_back();
 
	cout << "YES\n";
	for(int i: ret)
		cout << i << " ";
	cout << '\n';
}
 
int main()
{
	for(int i=1; i<=n-1; i++)
		bellman();
	int fin = bellman();
	if(fin)
		f_neg(fin);
	else
		cout << "NO\n";
}
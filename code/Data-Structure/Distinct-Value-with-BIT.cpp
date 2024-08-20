#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pti = pair<int, pii>;
 
int n, q, val[200005];
pti ques[200005];
pii ans[200005];
 
struct BIT
{
	int bit[200005];
	map<int, int> mp;
	//color, index
 
	void add(int idx, int dif)
	{
		while(idx <= n)
			bit[idx] += dif, idx += idx&-idx;
	}
 
	void update(int idx, int color)
	{
		if(mp.find(color) == mp.end())
		{
			add(idx, 1);
			mp.insert({color, idx});
		}
		else
		{
			add(mp[color], -1);
			add(idx, 1);
			mp[color] = idx;
		}
	}
 
	int query(int l, int r)
	{
		if(l != 1)
			return query(1, r) - query(1, l-1);
		int ret = 0;
		while(l <= r)
			ret += bit[r], r -= r&-r;
		return ret;
	}
}a;
 
bool cmp(const pti &x, const pti &y)
{
	if(x.second.second != y.second.second)
		return x.second.second < y.second.second;
	return x.second.first < y.second.first;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> q;
	for(int i=1; i<=n; i++)
		cin >> val[i];
	for(int i=0; i<q; i++)
	{
		cin >> ques[i].second.first >> ques[i].second.second;
		ques[i].first = i;
	}
	sort(ques, ques+q, cmp);
 
	int far = 0;
	for(int i=0; i<q; i++)
	{
		while(far < ques[i].second.second)
			a.update(far+1, val[far+1]), far++;
		ans[i] = {ques[i].first, a.query(ques[i].second.first, ques[i].second.second)};
	}
 
	sort(ans, ans+q);
	for(int i=0; i<q; i++)
		cout << ans[i].second << "\n";
}
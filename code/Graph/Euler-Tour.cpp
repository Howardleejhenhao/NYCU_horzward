#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
 
const int N = 1e5+5, M = 2e5+5;
 
vector<pii> a[N], edge;
int id[N];
bool vis[M];
vector<int> seq;
 
void dfs(int x)
{
    for(; id[x]<(int)a[x].size(); id[x]++)
    {
        int i = a[x][id[x]].first, j = a[x][id[x]].second;
        if(vis[j])
            continue;
        vis[j] = 1;
        dfs(i);
        seq.push_back(i);
    }
}
 
void no()
{
    cout << "IMPOSSIBLE\n";
    exit(0);
}
 
int main()
{
    seq.reserve(m + 1);
    dfs(1);
    seq.push_back(1);
 
	for(int i=1; i<=n; i++)
		if(a[i].size() % 2)
			no();
	for(int i=0; i<m; i++)
		if(!vis[i])
			no();
	if(seq.front() != 1)
		no();
	
	reverse(seq.begin(), seq.end());
	for(int i: seq)
		cout << i << " ";
	cout << "\n";
}
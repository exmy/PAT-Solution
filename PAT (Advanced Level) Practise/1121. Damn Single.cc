#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
using namespace std;

const int maxn = 100000 + 10;
int n, m;
int couple[maxn];
bool vis[maxn];

int main()
{
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif

	cin >> n;
	for(int i = 0; i < n; ++i){
		int id1, id2;
		cin >> id1 >> id2;
		couple[id1] = id2;
		couple[id2] = id1;
	}

	cin >> m;
	for(int i = 0; i < m; ++i){
		int id; cin >> id;
		vis[id] = 1;
	}

	vector<int> ans;
	for(int i = 0; i < maxn; ++i){
		if(vis[i] && !vis[couple[i]]) ans.push_back(i);
	}

	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); ++i){
		if(i) cout << " ";
		printf("%05d", ans[i]);
	}

	return 0;
}


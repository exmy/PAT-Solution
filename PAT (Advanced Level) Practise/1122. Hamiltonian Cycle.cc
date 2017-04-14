#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
using namespace std;

const int maxn = 200 + 10;
int n, m, k;
vector<int> G[maxn];

bool connect(int u, int v){
	for(int i = 0; i < G[u].size(); ++i){
		if(G[u][i] == v) return true;
	}
	return false;
}

bool judge(vector<int>& path){
	int len = path.size();

	if(len != n + 1) return false;
	if(path[0] != path[len - 1]) return false;

	vector<int> vis(path.begin(), path.end() - 1);
	sort(vis.begin(), vis.end());

	for(int i = 0; i < vis.size(); ++i){
		if(vis[i] != i + 1) return false;
	}

	for(int i = 0; i < path.size() - 1; ++i){
		int u = path[i], v = path[i + 1];
		if(!connect(u, v)) return false;
	}

	return true;
}


int main()
{
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif

	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; ++i){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	cin >> k;
	for(int i = 0; i < k; ++i){
		int t; cin >> t;
		vector<int> path;
		path.resize(t);
		for(int j = 0; j < t; ++j){
			cin >> path[j];
		}
		if(judge(path)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}


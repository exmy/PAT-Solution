#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 500 + 3;
const int inf  = 0x3f3f3f3f;
struct Edge{
	int to, w;
};

struct Node{
	int u, d;
	bool operator < (const Node& rhs) const{
		return d > rhs.d;
	}
};
vector<Edge> G[maxn];
int n, m, s, t;
int a[maxn];
int pathNum[maxn];
int dist[maxn];
bool vis[maxn];
int teams[maxn];

void Dijkstra(int s){
	for(int i = 0; i < n; ++i) dist[i] = inf;
	priority_queue<Node> Q;
	Q.push(Node{s, 0});
	dist[s] = 0;
	pathNum[s] = 1;
	teams[s] = a[s];

	while(!Q.empty()){
		Node p = Q.top();
		Q.pop();
		int u = p.u;

		if(vis[u]) continue;
		vis[u] = true;
		for(int i = 0; i < G[u].size(); ++i){
			int v = G[u][i].to, d = G[u][i].w;
			if(!vis[v]){
                if(dist[v] > dist[u] + d){
                    pathNum[v] = pathNum[u];
                    dist[v] = dist[u] + d;
                    teams[v] = teams[u] + a[v];
                    Q.push(Node{v, dist[v]});
                }
                else if(dist[v] == dist[u] + d){
                    teams[v] = max(teams[v], teams[u] + a[v]);
                    pathNum[v] += pathNum[u];
                }
            }
        }
	}
	cout << pathNum[t] << " " << teams[t] << endl;
}

// brute force searching every path !!!
int cnt, maxteams, mindist = inf;
void dfs(int u, int d, int teams){
    if(u == t){
        if(d < mindist) mindist = d, cnt = 1, maxteams = teams;
        else if(d == mindist) cnt++, maxteams = max(maxteams, teams);
        return;
    }
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i].to, w = G[u][i].w;
        if(!vis[v]) dfs(v, d + w, teams + a[v]);
    }
    vis[u] = false;
}

int main(){
#ifdef EXMY
freopen("data.in", "r", stdin);
#endif

	cin >> n >> m >> s >> t;
	for(int i = 0; i < n; ++i) cin >> a[i];
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(Edge{v, w});
		G[v].push_back(Edge{u, w});
	}
    Dijkstra(s);
//    dfs(s, 0, a[s]);
//    cout << cnt << " " << maxteams << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 500 + 5;
int n, m;
int deg[maxn];
vector<int> G[maxn];
int used[maxn];

int nodes = 0;
void dfs(int u){
    used[u] = 1;
    nodes++;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(!used[v]) dfs(v);
    }
}


void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(deg[i] & 1) cnt++;
        if((i - 1)) cout << " ";
        cout << deg[i];
    }
    cout << endl;

    dfs(1);
    bool connected = (nodes == n);
    if(connected && cnt == 0) cout << "Eulerian" << endl;
    else if(connected && cnt == 2) cout << "Semi-Eulerian" << endl;
    else cout << "Non-Eulerian" << endl;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; ++i){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);

        deg[u]++, deg[v]++;
    }

    solve();

    return 0;
}

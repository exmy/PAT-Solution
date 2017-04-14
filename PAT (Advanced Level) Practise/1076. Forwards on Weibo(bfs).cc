#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1000 + 10;
vector<int> G[maxn];
int layer[maxn];    // 记录节点的层次
int N, L, k;

void bfs(int id){
    queue<int> Q;
    Q.push(id);
    int ans = 0;
    fill(layer, layer + maxn, -1);
    layer[id] = 0;

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        if(layer[u] >= L) break;
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            if(layer[v] == -1){
                layer[v] = layer[u] + 1;
                Q.push(v);
                ans++;
            }
        }
    }

    cout << ans << endl;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> N >> L;
    for(int i = 1; i <= N; ++i){
        cin >> k;
        for(int j = 0; j < k; ++j){
            int v; cin >> v;
            G[v].push_back(i);
        }
    }
    cin >> k;
    for(int i = 0; i < k; ++i){
        int id; cin >> id;
        bfs(id);
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


const int maxn = 10000 + 10;
int n;
vector<int> G[maxn];
bool vis[maxn];
int  depth[maxn], p[maxn];

int find(int x){ return x == p[x] ? x : p[x] = find(p[x]); }

int dfs(int u){
    vis[u] = true;
    int deep = 0;
    for(int i = 0; i < (int)G[u].size(); ++i){
        if(!vis[G[u][i]]){
            vis[G[u][i]] = true;
            deep = max(deep, dfs(G[u][i]));
        }
    }
    return deep + 1;
}

int main(){
#ifdef LOCAL
freopen("data.in", "r", stdin);
#endif // LOCAL
    cin >> n;
    int u, v, cnt = n;
    for(int i = 1; i <= n; ++i) p[i] = i;
    for(int i = 0; i < n - 1; ++i){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);

        int x = find(u), y = find(v);
        if(x != y){
            p[x] = y;
            cnt--;
        }
    }

    if(cnt != 1){
        printf("Error: %d components\n", cnt);
    }
    else{
        int max_depth = 0;
        for(int i = 1; i <= n; ++i){
            memset(vis, 0, sizeof(vis));
            depth[i] = dfs(i);
            max_depth = max(max_depth, depth[i]);
        }
        for(int i = 1; i <= n; ++i){
            if(depth[i] == max_depth){
                printf("%d\n", i);
            }
        }
    }

    return 0;
}

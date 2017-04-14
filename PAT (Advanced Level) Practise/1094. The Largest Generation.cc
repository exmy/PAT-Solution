#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int maxn = 100;
vector<int> G[maxn];
map<int, int> mp;
int d[maxn];
int n, m;

void dfs(int u, int depth){
    d[u] = depth;
    mp[depth]++;
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        dfs(v, depth + 1);
    }
}

void bfs(){
    queue<int> Q;
    Q.push(1);
    int tail = 1, flag = 0;
    int level = 1, largest = 1, ansLevel = 1;
    int cnt = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        cnt += G[u].size();
        for(int i = 0; i < G[u].size(); ++i){
            int v = G[u][i];
            Q.push(v);
            flag = v;
        }
        if(u == tail){
            tail = flag;
            level++;
            if(cnt > largest){
                largest = cnt;
                ansLevel = level;
            }
            cnt = 0;
        }
    }
    cout << largest << " " << ansLevel << endl;
}


int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n >> m;
    int id, k, u;
    for(int i = 0; i < m; ++i){
        cin >> id >> k;
        for(int j = 0; j < k; ++j){
            cin >> u;
            G[id].push_back(u);
        }
    }
    dfs(1, 1);
    int level = 0, largest = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it->second > largest){
            largest = it->second;
            level = it->first;
        }
    }
    cout << largest << " " << level << endl;
//    bfs();

    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100000 + 5;
const int inf  = 0x3f3f3f3f;
int n, k, t;
double p, r;
vector<int> G[maxn];
int minDepth = inf, minNum = 1;

void dfs(int u, int depth){
    if(G[u].size() == 0){
        if(depth == minDepth) minNum++;
        if(depth < minDepth){
            minDepth = depth;
            minNum = 1;
        }
    }
    for(int i = 0; i < G[u].size(); ++i) dfs(G[u][i], depth + 1);
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n >> p >> r;
    for(int i = 0; i < n; ++i){
        cin >> k;
        for(int j = 0; j < k; ++j){
            cin >> t;
            G[i].push_back(t);
        }
    }
    dfs(0, 0);

    printf("%.4f %d\n", p * pow(1 + r/100, minDepth), minNum);

    return 0;
}

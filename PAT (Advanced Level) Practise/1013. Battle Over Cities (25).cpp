#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
const int maxe = (maxn + 1) * maxn / 2;
int  u[maxe], v[maxe];
int  p[maxn];
int  n, m, k, id;

int  find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void Union(int u, int v)
{
    int x = find(u), y = find(v);
    if(x != y) p[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    if(m == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < m; ++i) cin >> u[i] >> v[i];
    while(k--)
    {
        cin >> id;
        for(int i = 1; i <= n; ++i) p[i] = i;
        for(int i = 0; i < m; ++i)
        {
            if(u[i] != id && v[i] != id) Union(u[i], v[i]);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
            if(p[i] == i && i != id) cnt++;
        cout << cnt - 1 << endl;
    }
    return 0;
}

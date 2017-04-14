#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
const int inf  = 0x3f3f3f3f;
int p[maxn], tmp[maxn];
int n, k, q;

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void Union(int u, int v){
    int pu = find(u), pv = find(v);
    if(pu != pv) p[pu] = pv;
}

int main(){
#ifdef EXMY
freopen("data.in", "r", stdin);
#endif // EXMY
    for(int i = 1; i < maxn; ++i) p[i] = i;
    int tot = 0;
    int Max = -inf;
    cin >> n;
    while(n--){
        cin >> k;
//        bool flag = false;
//        int idx;
//        for(int i = 0; i < k; ++i){
//            scanf("%d", tmp + i);
//            if(p[tmp[i]]) flag = true, idx = p[tmp[i]];
//        }
//        tot = flag ? idx: tot + 1;
//        for(int i = 0; i < k; ++i) p[tmp[i]] =  tot;

        int t, r;
        cin >> t;
        Max = max(Max, t);
        for(int i = 1; i < k; ++i){
            cin >> r;
            Max = max(Max, r);
            Union(t, r);
            t = r;
        }
    }

//    for(int i= 1; i <= 10; ++i) cout << p[i] << " ";
//    cout << endl;

//    int sum = 0;
//    for(int i = 0; i < maxn; ++i) if(p[i]) sum++;
//    cout << tot << " " << sum << endl;

    for(int i = 1; i <= Max; ++i){
        if(p[i] == i) tot++;
    }
    cout << tot << " " << Max << endl;


    cin >> q;
    int u, v;
    while(q--){
        scanf("%d %d", &u, &v);
        if(find(u) == find(v)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}


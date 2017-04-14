#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int a[maxn];
int n;

int main(){
#ifdef EXMY
freopen("data.in", "r", stdin);
#endif // EXMY
    while(cin >> n){
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        sort(a, a + n);
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(n - i < a[i]){
                ans = n - i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

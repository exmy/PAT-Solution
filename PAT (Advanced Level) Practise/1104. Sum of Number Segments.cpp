#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;
double a[maxn];
int n;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%lf", a + i);
    }
    double ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += a[i] * i * (n - i + 1);
    }

    printf("%.2f\n", ans);

    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int  a[maxn];
int  n, p;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> p;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    int ans = 0;
    for(int i = 0; i < n; ++i)
    {
        ll  ax = (ll)a[i] * p;
        int len = upper_bound(a, a + n, ax) - a;
        cout << len << endl;
        ans = max(ans, len - i);
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int n, k, pos;
int chess[3][2 * maxn];

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> k;
    while(k--){
        cin >> n;
        int flag = 1;
        memset(chess, 0, sizeof(chess));
        for(int i = 1; i <= n; ++i){
            cin >> pos;
            if(chess[0][pos] || chess[1][pos + i] || chess[2][pos - i + n]) flag = 0;
            chess[0][pos] = 1;
            chess[1][pos + i] = 1;
            chess[2][pos - i + n] = 1;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}

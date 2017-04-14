#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 3;
double a[maxn], b[maxn], x[2 * maxn];

void product(){
    for(int i = 0; i < maxn; ++i){
        for(int j = 0; j < maxn; ++j){
            x[i + j] += a[i] * b[j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < 2 * maxn; ++i){
        if(x[i] != 0.0) cnt++;
    }
    cout << cnt;
    cout << fixed << setprecision(1);
    for(int i = 2 * maxn - 1; i >= 0; --i){
        if(x[i] != 0.0){
            cout << " " << i << " " << x[i];
        }
    }
}

void add(){
    for(int i = 0; i < maxn; ++i){
        x[i] += a[i] + b[i];
    }
    int cnt = 0;
    for(int i = 0; i < maxn; ++i){
        if(x[i] != 0.0) cnt++;
    }
    cout << cnt;
    cout << fixed << setprecision(1);
    for(int i = maxn - 1; i >= 0; --i){
        if(x[i] != 0.0){
            cout << " " << i << " " << x[i];
        }
    }
}

int main(){
#ifdef EXMY
freopen("data.in", "r", stdin);
#endif // EXMY

    int n1, n2;
    int e;
    double c;
    cin >> n1;
    for(int i = 0; i < n1; ++i){
        cin >> e >> c;
        a[e] = c;
    }

    cin >> n2;
    for(int i = 0; i < n2; ++i){
        cin >> e >> c;
        b[e] = c;
    }

    //product();
    add();
    return 0;
}

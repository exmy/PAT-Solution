#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Mooncake{
    int    amount;
    double prices;
    bool operator < (const Mooncake& rhs){
        return (prices / amount) > (rhs.prices / rhs.amount);
    }
};

int n, m;
Mooncake arrMoon[1010];

/**
3 200
180 150 100
7.5 7.2 4.5
*/
void solve(){
    sort(arrMoon, arrMoon + n);
    double ans = 0;
    int i = 0;
    for(; i < n; ++i){
        if(m >= arrMoon[i].amount){
            ans += arrMoon[i].prices;
            m -= arrMoon[i].amount;
        }
        else{
            ans += m * arrMoon[i].prices / arrMoon[i].amount;
            break;
        }
    }
    printf("%.2f\n", ans);
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arrMoon[i].amount;
    for(int i = 0; i < n; ++i) cin >> arrMoon[i].prices;

    solve();

    return 0;
}

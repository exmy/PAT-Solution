#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 10000 + 5;
double a[maxn];
int n;
priority_queue<double, vector<double>, greater<double>> pq;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        pq.push(a[i]);
    }

    for(int i = 1; i < n; ++i){
        double s1 = pq.top(); pq.pop();
        double s2 = pq.top(); pq.pop();
        pq.push((s1 + s2) / 2);
    }

    cout << floor(pq.top()) << endl;

    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 10000 + 10;
int a[maxn];

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    int msize, n, num, t;
    cin >> msize >> n;
    while(!isPrime(msize)) msize++;
    for(int i = 0; i < n; ++i){
        scanf("%d", &num);
        int pos = num % msize, j ;
        for(j = 0; j < msize; ++j){
            if(a[t = (pos + j * j) % msize] == 0){
                a[pos = t] = 1;
                break;
            }
        }
        if(i) printf(" ");
        if(j < msize) printf("%d", pos);
        else printf("-");
    }


    return 0;
}

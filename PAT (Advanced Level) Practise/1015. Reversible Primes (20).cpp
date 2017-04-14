#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int n){

    if(n < 2) return false;

    int k = sqrt(n);
    for(int i = 2; i <= k; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

bool solve(int N, int D){

    if(!isPrime(N)) return false;

    string n;
    while(N){
        n += N % D + '0';
        N /= D;
    }
    int res = 0;
    for(int i = 0; i < n.length(); ++i){
        res = res * D + (n[i] - '0');
    }

    return isPrime(res);
}

int main(){

    int N, D;
    while(cin >> N && N >= 0){
        cin >> D;
        cout << (solve(N, D) ? "Yes" : "No") << endl;
    }

    return 0;
}

/**
###题解
1. 判断N是否为素数；
2. N转换为D进制下的数，reverse之后再转换为十进制，判断是否为素数。
*/

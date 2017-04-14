#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int n;
string a, b;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE
    cin >> n >> a >> b;
    int pos;
    // 小数点
    int dota = (((pos = a.find('.')) != string::npos) ? pos : a.length());
    int dotb = (((pos = b.find('.')) != string::npos) ? pos : b.length());

    // 去除前导0  e.g. 0.123
    // 从有效数位开始
    int p = 0, q = 0;
    while(a[p] == '0' || a[p] == '.') p++;
    while(b[q] == '0' || b[q] == '.') q++;

    // 指数，当然可以是负的
    int exp_a = 0, exp_b = 0;
    if(dota >= p) exp_a = dota - p;
    else exp_a = dota - p + 1;
    if(dotb >= q) exp_b = dotb - q;
    else exp_b = dotb - q + 1;

    // 处理为0的情况, 000, 指数为0
    if(p == a.length()) exp_a = 0;
    if(q == b.length()) exp_b = 0;

    // 如果n大于位数，补0
    // e.g. 5 0.123 --> 0.12300*10^-1
    string A, B;
    int indexA = 0, indexB = 0;
    while(indexA < n){
        if(a[p] != '.' && p < a.length()) A += a[p], indexA++;
        else if(p >= a.length()) A += '0', indexA++;
        p++;
    }
    while(indexB < n){
        if(b[q] != '.' && q < b.length()) B += b[q], indexB++;
        else if(q >= b.length()) B += '0', indexB++;
        q++;
    }
    // 指数相等, 有效数字部分相等
    if(A == B && exp_a == exp_b){
        printf("YES 0.%s*10^%d\n", A.c_str(), exp_a);
    }else{
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", A.c_str(), exp_a, B.c_str(), exp_b);
    }

    return 0;
}

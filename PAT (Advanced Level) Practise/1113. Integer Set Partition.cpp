#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100000 + 10;
int   n, a[maxn];

int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        sort(a, a + n);
        int s1 = 0, s2 = 0;
        if(n & 1){
            for(int i = 0; i <= n / 2 - 1; ++i){
                s1 += a[i];
                s2 += a[n - i - 1];
            }
            s2 += a[n / 2];
            cout << 1 << " " << s2 - s1 << endl;
        }
        else{
            for(int i = 0; i < n / 2; ++i){
                s1 += a[i];
                s2 += a[n - i - 1];
            }
            cout << 0 << " " << s2 - s1 << endl;
        }
    }
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int Rank[maxn];
bool check[maxn];
int n, tmp, q;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
#ifdef EXMY
freopen("data.in", "r", stdin);
#endif // EXMY
    while(cin >> n){
        memset(Rank, 0, sizeof(Rank));
        memset(check, 0, sizeof(check));
        for(int i = 1; i <= n; ++i){
            scanf("%d", &tmp);
            Rank[tmp] = i;
        }
        cin >> q;
        while(q--){
            cin >> tmp;
            if(Rank[tmp] == 1) {
                if(check[tmp]) printf("%04d: %s\n", tmp, "Checked");
                else{
                    check[tmp] = true;
                    printf("%04d: %s\n", tmp, "Mystery Award");
                }
            }else if(isPrime(Rank[tmp])){
                if(check[tmp]) printf("%04d: %s\n", tmp, "Checked");
                else{
                    check[tmp] = true;
                    printf("%04d: %s\n", tmp, "Minion");
                }
            }else if(Rank[tmp]){
                if(check[tmp]) printf("%04d: %s\n", tmp, "Checked");
                else{
                    check[tmp] = true;
                    printf("%04d: %s\n", tmp, "Chocolate");
                }
            }else{
                printf("%04d: %s\n", tmp, "Are you kidding?");
            }
        }
    }
    return 0;
}

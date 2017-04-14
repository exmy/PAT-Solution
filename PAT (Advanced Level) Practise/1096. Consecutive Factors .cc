#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    vector<int> ans(1, n);
    for(ll i = 2; i * i <= n; ++i){
        vector<int> tmp;
        ll num = n;
        for(ll j = i; j <= num; ++j){
            if(num % j == 0){
                tmp.push_back(j);
                num /= j;
            }else break;
        }
        if(tmp.size() > ans.size()){
            ans = tmp;
        }else if(tmp.size() == ans.size() && tmp[0] < ans[0]) ans = tmp;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        if(i) cout << "*";
        cout << ans[i];
    }
    return 0;
}

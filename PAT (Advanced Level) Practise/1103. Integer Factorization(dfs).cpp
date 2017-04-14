#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

int n, k, p;
int maxFacSum = -1;
vector<int> ans;
vector<int> tmp;
vector<int> fac;

void dfs(int i, int tempK, int curSum, int facSum){
    if(tempK > k || curSum > n) return;
    if(curSum == n && tempK == k){
        if(facSum > maxFacSum){
            maxFacSum = facSum;
            ans = tmp;
        }
        return;
    }
//    for(int i = 1; i < fac.size(); ++i){
//        tmp.push_back(i);
//        dfs(tempK + 1, curSum + fac[i], facSum + i);
//        tmp.pop_back();
//    }
    // note that the strategy of searching
    if(i >= 1){
        tmp.push_back(i);
        dfs(i, tempK + 1, curSum + fac[i], facSum + i);
        tmp.pop_back();
        dfs(i - 1, tempK, curSum, facSum);
    }
}

int mypow(int x, int p){
    int ret = 1;
    for(int i = 1; i <= p; ++i){
        ret *= x;
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n >> k >> p;
    for(int i = 0; ; ++i){
        int t = mypow(i, p);
        if(t > n) break;
        fac.push_back(t);
    }

    dfs(fac.size() - 1, 0, 0, 0);
    if(maxFacSum == -1){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << n << " = ";
    for(int i = 0; i < ans.size(); ++i){
        if(i) cout << " + ";
        printf("%d^%d", ans[i], p);
    }

    return 0;
}

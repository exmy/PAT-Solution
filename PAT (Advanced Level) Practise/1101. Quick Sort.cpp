#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 100000 + 5;
int a[maxn];
int n;
bool L[maxn], R[maxn];

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 0; i < n; ++i) scanf("%d", a + i);
    int Max = a[0];
    L[0] = true;
    for(int i = 1; i < n; ++i){
        if(a[i] > Max){
            L[i] = true;
            Max = a[i];
        }
    }
    int Min = a[n - 1];
    R[n - 1] = true;
    for(int i = n - 2; i >= 0; --i){
        if(a[i] < Min){
            R[i] = true;
            Min = a[i];
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(L[i] && R[i]) ans.push_back(a[i]);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

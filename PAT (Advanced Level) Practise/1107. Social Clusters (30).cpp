#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn = 1000 + 5;
int p[maxn];
int n;
int tot;
vector<int> vec[maxn];

int find(int x){ return x == p[x] ? x : p[x] = find(p[x]); }
void Union(int x, int y){
    x = find(x), y = find(y);
    if(x != y){
        tot--;
        p[x] = y;
    }
}

bool common(vector<int>& v1, vector<int>& v2){
    for(auto i : v1){
        for(auto j : v2){
            if(i == j) return true;
        }
    }
    return false;
}


int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    for(int i = 0; i < maxn; ++i) p[i] = i;

    cin >> n;
    int k, u;
    char ch;
    for(int i = 0; i < n; ++i){
        cin >> k >> ch;
        for(int j = 0; j < k; ++j) {
            cin >> u;
            vec[i].push_back(u);
        }
    }
    tot = n;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(common(vec[i], vec[j])){
                Union(i + 1, j + 1);
            }
        }
    }
    // 每个集合的根
    vector<int> roots;
    for(int i = 1; i <= n; ++i){
        if(find(i) == i) roots.push_back(i);
    }
    cout << tot << endl;

    // map 统计每个集合的大小
    map<int, int> mp;
    for(auto root: roots){
        for(int i = 1; i <= n; ++i){
            if(find(i) == root) mp[root]++;
        }
    }
    // 用于排序
    vector<int> tmp;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        tmp.push_back(it->second);
    }
    sort(tmp.begin(), tmp.end(), [](int a, int b){ return a > b;} );
    for(int i = 0; i < tmp.size(); ++i){
        if(i) cout << " ";
        cout << tmp[i];
    }
    cout << endl;
    return 0;
}

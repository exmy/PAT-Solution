#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 50000 + 5;
int n, k;
int items[maxn];

struct Item{
    int value;
    int cnt;
    Item(int v, int c):value(v), cnt(c){}
};

bool operator < (const Item& a, const Item& b){
    if(a.cnt == b.cnt) return a.value < b.value;
    return a.cnt > b.cnt;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> items[i];

    map<int, int> mp1;
    map<Item, int> mp2;

    mp1[items[0]]++;
    mp2.insert(make_pair(Item{items[0], 1}, 1));
    for(int i = 1; i < n; ++i){
        int j = 0;
        cout << items[i] << ": ";
        for(auto it = mp2.begin(); it != mp2.end() && j < k; ++it, j++){
            if(j) cout << " ";
            cout << it->first.value;
        }
        cout << endl;

        mp1[items[i]]++;
        int cnt = mp1[items[i]];
        if(cnt == 1) mp2.insert(make_pair(Item{items[i], cnt}, 1));
        else{
            auto oldkey = mp2.find(Item{items[i], cnt - 1});
            mp2.erase(oldkey);

            mp2.insert(make_pair(Item{items[i], cnt}, 1));
        }
    }

    return 0;
}

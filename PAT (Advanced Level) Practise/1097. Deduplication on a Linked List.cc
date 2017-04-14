#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

const int maxn = 100000 + 5;

struct Node{
    int key;
    int next;
};
Node linklist[maxn];
int n, head;
set<int> Set;
vector<pair<int, Node> > res;
vector<pair<int, Node> > rem;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    for(int i = 0; i < maxn; ++i) linklist[i].next = -1;

    cin >> head >> n;
    int address, key, next;
    for(int i = 0; i < n; ++i){
        cin >> address >> key >> next;
        linklist[address].key = key;
        linklist[address].next = next;
    }

    for(int i = head; ~i; i = linklist[i].next){
        if(!Set.count(abs(linklist[i].key))) {
            Set.insert(abs(linklist[i].key));
            res.push_back(make_pair(i, linklist[i]));
            if(!rem.empty()){
                rem[rem.size()-1].second.next = linklist[i].next;
            }
        }else{
            if(!res.empty()){
                res[res.size()-1].second.next = linklist[i].next;
            }
            rem.push_back(make_pair(i, linklist[i]));
        }
    }
    int len = res.size();
    for(int i = 0; i < len - 1; ++i){
        printf("%05d %d %05d\n", res[i].first, res[i].second.key, res[i].second.next);
    }
    if(len > 0) printf("%05d %d %d\n", res[len-1].first, res[len-1].second.key, res[len-1].second.next);

    len = rem.size();
    for(int i = 0; i < len - 1; ++i){
        printf("%05d %d %05d\n", rem[i].first, rem[i].second.key, rem[i].second.next);
    }
    if(len > 0) printf("%05d %d %d\n", rem[len-1].first, rem[len-1].second.key, rem[len-1].second.next);

    return 0;
}

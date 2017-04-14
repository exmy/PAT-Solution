#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 100;

struct node{
    int left, right;
};
int n;
int tree[maxn];
node a[maxn];
int appear[maxn];

void build(int root, int t){
    if(root == -1) return;

    tree[t] = root;
    build(a[root].left,  t*2 + 1);
    build(a[root].right, t*2 + 2);
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    string s1, s2;
    for(int i = 0; i < n; ++i){
        cin >> s1 >> s2;
        a[i].left  = (s1 == "-") ? -1 : atoi(s1.c_str());
        a[i].right = (s2 == "-") ? -1 : atoi(s2.c_str());
        if(a[i].left  != -1) appear[a[i].left]  = true;
        if(a[i].right != -1) appear[a[i].right] = true;
    }
    int root = -1;
    for(int i = 0; i < n; ++i){
        if(!appear[i]){
            root = i;
            break;
        }
    }
    memset(tree, -1, sizeof(tree));
    build(root, 0);
    bool ans = true;
    for(int i = 0; i < n; ++i){
        if(tree[i] == -1){
            ans = false;
            break;
        }
    }
    if(ans) printf("YES %d\n", tree[n - 1]);
    else printf("NO %d\n", tree[0]);

    return 0;
}

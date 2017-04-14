#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

// remain
const int maxn = 100 + 10;
struct Node{
    int left, right;
    int key;
};
int n, a[maxn];
Node tree[maxn];
int t;

void inorder(int root){
    if(root == -1) return;
    inorder(tree[root].left);
    tree[root].key = a[t++];
    inorder(tree[root].right);
}

void bfs(){
    queue<int> Q;
    vector<int> ans;
    Q.push(0);
    while(!Q.empty()){
        int u = Q.front();Q.pop();
        ans.push_back(tree[u].key);
        if(tree[u].left != -1)  Q.push(tree[u].left);
        if(tree[u].right != -1) Q.push(tree[u].right);
    }

    for(int i = 0; i < ans.size(); ++i){
        if(i) cout << " ";
        cout << ans[i];
    }
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tree[i].left >> tree[i].right;
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a + n);
    inorder(0);
    bfs();

    return 0;
}

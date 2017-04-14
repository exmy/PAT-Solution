#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100;

struct node{
    int left, right;
};
int n;
//int tree[maxn];
node a[maxn];
int appear[maxn];
//int k;
vector<int> in;

//int build(int root, int t){
//    if(root == -1) return 0;
//
//    tree[t] = root;
//    int d1 = build(a[root].left,  t*2 + 1);
//    int d2 = build(a[root].right, t*2 + 2);
//    return max(d1, d2) + 1;
//}

void inorder(int root){
    if(root == -1) return;
    inorder(a[root].left);
    in.push_back(root);
    inorder(a[root].right);
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    string s1, s2;
    for(int i = 0; i < n; ++i){
        cin >> s1 >> s2;
        a[i].right  = (s1 == "-") ? -1 : atoi(s1.c_str());
        a[i].left = (s2 == "-") ? -1 : atoi(s2.c_str());
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
//    memset(tree, -1, sizeof(tree));
//    k = build(root, 0);
//    cout << root << endl;
//    cout << k << endl;
//    for(int i = 0; i < ((k+1) << 1); ++i){
//        if(tree[i] != -1) cout << tree[i] << " ";
//    }
    // level order
    queue<int> Q;
    Q.push(root);
    vector<int> level;
    while(!Q.empty()){
        int p = Q.front();
        Q.pop();
        level.push_back(p);
        if(a[p].left  != -1) Q.push(a[p].left);
        if(a[p].right != -1) Q.push(a[p].right);
    }
    for(int i = 0; i < level.size(); ++i){
        if(i) cout << " ";
        cout << level[i];
    }
    cout << endl;

    inorder(root);
    for(int i = 0; i < in.size(); ++i){
        if(i) cout << " ";
        cout << in[i];
    }
    cout << endl;

    return 0;
}

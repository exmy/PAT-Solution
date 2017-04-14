#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 50 + 5;
int n;
int in[maxn], post[maxn];

struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k):key(k), left(NULL), right(NULL){}
};

TreeNode* build(int* in, int* post, int n){
    if(n == 0) return NULL;
    TreeNode* node = new TreeNode(post[n - 1]);
    int pos = 0;
    for(; pos < n && in[pos] != post[n - 1]; ++pos) ;
    int left = pos, right = n - pos - 1;
    node->left = build(in, post, left);
    node->right = build(in + left + 1, post + left, right);

    return node;
}

void zigzagging(TreeNode* root){
    queue<TreeNode*> Q;
    vector<vector<int>> ans;
    vector<int> tmp;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        TreeNode* p = Q.front(); Q.pop();
        if(p == NULL){
            ans.push_back(tmp);
            tmp.clear();
            if(Q.size() > 0) Q.push(NULL);
        }else{
            tmp.push_back(p->key);
            if(p->left)  Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
    }

    for(int i = 0; i < ans.size(); ++i){
        if(i && i % 2 == 0) reverse(ans[i].begin(), ans[i].end());
    }

    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            if(i || j) cout << " ";
            cout << ans[i][j];
        }
    }

}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> in[i];
    for(int i = 0; i < n; ++i) cin >> post[i];

    TreeNode* root = build(in, post, n);
    zigzagging(root);

    return 0;
}

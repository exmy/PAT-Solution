#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int v):val(v), left(NULL), right(NULL){}
};

int inorder[35], postorder[35];

node* build(int* in, int* post, int n){
    if(n == 0) return NULL;

    node* root = new node(post[n - 1]);

    int p = 0;
    while(in[p] != post[n - 1]) p++;
    root->left  = build(in, post, p);
    root->right = build(in + p + 1, post + p, n - p - 1);

    return root;
}

void level(node* root, int n){
    queue<node*> Q;
    Q.push(root);

    while(!Q.empty()){
        node* p = Q.front(); Q.pop();
        cout << p->val;
        if(--n) cout << " ";
        if(p->left)  Q.push(p->left);
        if(p->right) Q.push(p->right);
    }
}

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> postorder[i];
    for(int i = 0; i < n; ++i) cin >> inorder[i];

    node* root = build(inorder, postorder, n);
    level(root, n);

    return 0;
}

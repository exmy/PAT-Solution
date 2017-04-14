#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 200 + 5;
struct Node{
    string val;
    int left, right;
};

Node nodes[maxn];
int n, root_num;
int numbers[maxn];

void infix(int root){
    if(root == -1) return;

    if(root != root_num && (nodes[root].left != -1 || nodes[root].right != -1)) cout << "(";
    infix(nodes[root].left);

    cout << nodes[root].val;

    infix(nodes[root].right);
    if(root != root_num && (nodes[root].left != -1 || nodes[root].right != -1)) cout << ")";

}

string infix1(int root){
    if(root == -1) return "";

    if(nodes[root].right != -1){
        nodes[root].val = infix1(nodes[root].left) + nodes[root].val + infix1(nodes[root].right);
        if(root != root_num) nodes[root].val = "(" + nodes[root].val + ")";
    }

    return nodes[root].val;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    string val; int left, right;
    for(int i = 1; i <= n; ++i){
        cin >> val >> left >> right;
        nodes[i] = Node{val, left, right};
        if(left != -1)  numbers[left] = 1;
        if(right != -1) numbers[right] = 1;
    }

    // find the root of the tree
    for(int i = 1; i <= n; ++i) if(!numbers[i]) root_num = i;

    cout << infix1(root_num) << endl;
//    infix(root_num);
    return 0;
}

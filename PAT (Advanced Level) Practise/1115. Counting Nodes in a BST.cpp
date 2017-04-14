#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node* BinTree;
struct node{
    int k;
    int l;
    BinTree left, right;
    node(int _k, int _l):k(_k), l(_l), left(0), right(0){}
};

int n1, n2;
int p = -10000;

BinTree Insert(BinTree T, int k, int l)
{
    p = max(p, l);
    if(!T) T = new node(k, l);
    else if(k <= T->k)
        T->left = Insert(T->left, k, l + 1);
    else if(k > T->k)
        T->right = Insert(T->right, k, l + 1);
    return T;
}

void traversal(BinTree T)
{
    if(!T) return;

    if(T->l == p - 1) n2++;
    if(T->l == p) n1++;
    traversal(T->left);
    traversal(T->right);
}

int main()
{
    int n, a;
    BinTree root = NULL;

    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        root = Insert(root, a, 1);
    }
    traversal(root);
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
}

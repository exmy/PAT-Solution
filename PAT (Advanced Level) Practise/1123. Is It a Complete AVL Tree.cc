#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
using namespace std;

const int maxn = 30;

typedef struct Node* AVLTree;
struct Node{
	int key;
	Node* left;
	Node* right;
	int height;
	Node(int k):key(k), left(NULL), right(NULL), height(0){}
	Node(){}
};
int n;

int height(Node *node){
	return node ? node->height : -1;
}

Node* LL(Node* k2){
    Node* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k2->left), k2->height) + 1;

    return k1;
}
Node* RR(Node* k2){
    Node* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->right), k2->height) + 1;

    return k1;
}
Node* LR(Node* k3){
    k3->left = RR(k3->left);
    return LL(k3);
}
Node* RL(Node* k3){
    k3->right = LL(k3->right);
    return RR(k3);
}

Node* insert(AVLTree root, int key){
	if(!root) root = new Node(key);
	else if(root->key < key){
		root->right = insert(root->right, key);
		if(height(root->right) - height(root->left) == 2){
            if(key > root->right->key) root = RR(root);
            else root = RL(root);
		}
	}
	else if(root->key > key){
		root->left = insert(root->left, key);
		if(height(root->left) - height(root->right) == 2){
            if(key < root->left->key) root = LL(root);
            else root = LR(root);
		}
	}

	root->height = 1 + max(height(root->left), height(root->right));
	return root;
}

void level(AVLTree root){
	queue<Node*> Q;
	vector<int> levelSeq;
	Q.push(root);

	while(!Q.empty()){
		root = Q.front(); Q.pop();
		levelSeq.push_back(root->key);
		if(root->left)   Q.push(root->left);
		if(root->right)  Q.push(root->right);
	}

	for(int i = 0; i < levelSeq.size(); ++i){
		if(i) cout << " ";
		cout << levelSeq[i];
	}
}

bool isCompleteAVLTree(AVLTree root){
	queue<Node*> Q;
	Q.push(root);
	bool haveNULL = false;

	while(!Q.empty()){
		root = Q.front(); Q.pop();
		if(haveNULL){
			if(root->left || root->right) return false;
		}
		if(root->left && root->right){
			Q.push(root->left);
			Q.push(root->right);
		}else if(root->left && !root->right){
			Q.push(root->left);
			haveNULL = true;
		}else if(!root->left && root->right) return false;
		else haveNULL = true;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif

	cin >> n;
	int key;
	AVLTree root = NULL;
	for(int i = 0; i < n; ++i){
		cin >> key;
		root = insert(root, key);
	}

	level(root);
	printf("\n%s", isCompleteAVLTree(root) ? "YES" : "NO");

	return 0;
}

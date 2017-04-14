#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 35;
int pre[maxn], post[maxn];
int n;
vector<int> in;
bool flag = true;

void toInOrder(int prel, int prer, int postl, int postr){
    if(prel == prer){
        in.push_back(pre[prel]);
        return;
    }
    if(pre[prel] == post[postr]){
        int l = prel + 1, r = prer;
        int idx = -1;
        for(int i = l; i <= r; ++i) if(pre[i] == post[postr - 1]) { idx = i; break; }
        if(idx - prel > 1){
            toInOrder(prel + 1, idx - 1, postl, postl + idx - prel - 2);
            in.push_back(post[postr]);
            toInOrder(idx, prer, postl + idx - prel - 1, postr - 1);
        }else{
            flag = false;
            in.push_back(post[postr]);
            toInOrder(idx, prer, postl + idx - prel - 1, postr - 1);
        }
    }
}

int main(){
#ifdef EXMY
freopen("data.in", "r", stdin);
#endif // EXMY

    while(cin >> n){
        for(int i = 0; i < n; ++i) scanf("%d", pre + i);
        for(int i = 0; i < n; ++i) scanf("%d", post + i);
        in.clear();
        toInOrder(0, n - 1, 0, n - 1);
        cout << (flag ? "Yes" : "No") << endl;
        for(int i = 0; i < in.size(); ++i){
            if(i) cout << " ";
            cout << in[i];
        }
        cout << endl;
    }


    return 0;
}

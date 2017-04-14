#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100 + 10;
vector<int> a, b;
int n;
int flag;

bool insertSort(vector<int> tmp){
    for(int i = 1; i < n; ++i){
        int t = a[i], j;
        for(j = i; j > 0 && tmp[j - 1] > t; j--) tmp[j] = tmp[j - 1];
        tmp[j] = t;

        if(flag == 1){
            cout << "Insertion Sort" << endl;
            for(int i = 0; i < tmp.size(); ++i){
                if(i) cout << " ";
                cout << tmp[i];
            }
            return true;
        }
        if(tmp == b)  flag = 1;
    }
    return false;
}

int leftchild(int i){ return i << 1 | 1; }
void sink(vector<int>& tmp, int i, int n){
    int child, t;
    for(t = tmp[i]; leftchild(i) < n; i = child){
        child = leftchild(i);
        if(child != n - 1 && tmp[child] < tmp[child + 1]) child++;
        if(t < tmp[child]) tmp[i] = tmp[child];
        else break;
    }
    tmp[i] = t;
}
void heapSort(vector<int> tmp){
    for(int i = tmp.size() / 2 - 1; i >= 0; --i)
        sink(tmp, i, tmp.size());
    for(int j = tmp.size() - 1; j > 0; --j){
        swap(tmp[0], tmp[j]);
        sink(tmp, 0, j);

        if(flag){
            cout << "Heap Sort" << endl;
            for(int i = 0; i < tmp.size(); ++i){
                if(i) cout << " ";
                cout << tmp[i];
            }
            return;
        }
        if(tmp == b) flag = 1;
    }
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    int t;
    for(int i = 0; i < n; ++i){
        cin >> t; a.push_back(t);
    }
    for(int i = 0; i < n; ++i){
        cin >> t; b.push_back(t);
    }

    if(!insertSort(a)) heapSort(a);

    return 0;
}

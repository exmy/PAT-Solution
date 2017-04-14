#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int hash_a[128];
int hash_b[128];

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); ++i) hash_a[a[i]]++;
    for(int i = 0; i < b.length(); ++i) hash_b[b[i]]++;

    int more = 0, miss = 0;
    for(int i = 0; i < 128; ++i){
        if(hash_a[i] >= hash_b[i]){
            more += hash_a[i] - hash_b[i];
        }else{
            miss += hash_b[i] - hash_a[i];
        }
    }
    if(miss){
        cout << "No " << miss << endl;
    }else{
        cout << "Yes " << more << endl;
    }


    return 0;
}

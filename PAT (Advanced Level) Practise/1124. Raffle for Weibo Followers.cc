#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

const int maxn = 1000 + 5;
int m, n, s;
string candidates[maxn];


int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> m >> n >> s;
    for(int i = 1; i <= m; ++i){
        cin >> candidates[i];
    }

    vector<string> ans;
    set<string> Set;
    for(int i = s; i <= m;){
        if(Set.count(candidates[i]) == 0){
            ans.push_back(candidates[i]);
            Set.insert(candidates[i]);
            i += n;
        }else{
            i++;
        }
    }
    if(ans.empty()) cout << "Keep going..." << endl;
    else{
        for(string s : ans) cout << s << endl;
    }

    return 0;
}

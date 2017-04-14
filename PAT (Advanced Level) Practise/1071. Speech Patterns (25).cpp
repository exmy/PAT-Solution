#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
using namespace std;

string convert(string& s){
    string ss;
    for(int i = 0; i < s.length(); ++i){
        ss += tolower(s[i]);
    }
    return ss;
}

void solve(string& s){
    string word;
    map<string, int> mp;
    for(int i = 0; i < s.length(); ++i){
        if(isalnum(s[i])){
            word += s[i];
        }
        else if(!word.empty()){
            mp[convert(word)]++;
            word.clear();
        }
    }
    int maxCount = 0;
    string ans;
    for(auto it = mp.begin(); it != mp.end(); ++it){
//        cout << it->first << " " << it->second << endl;
        if(it->second > maxCount){
            ans = it->first;
            maxCount = it->second;
        }
    }
    cout << ans << " " << maxCount << endl;
}

int main(){
    string s;
    getline(cin, s);
    s.push_back('\n');  // 方便最后一个 word 的识别
    solve(s);
    return 0;
}

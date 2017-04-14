#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

map<string, int> mp;

string toMars(int n){
    if(n == 0){
        return string("tret");
    }
    vector<string> ret;
    int w = 1;
    while(n){
        int t = (n % 13) * w;
        if(t){  // tricky, 13 --> "tam", not "tam tret"
            for(auto it = mp.begin(); it != mp.end(); ++it){
                if(it->second == t){
                    ret.push_back(it->first);
                    break;
                }
            }
        }
        n /= 13;
        w *= 13;
    }
    string s;
    int k = 0;
    for(int i = ret.size() - 1; i >= 0; --i){
        if(k++) s += " ";
        s += ret[i];
    }
    return s;
}

int toDecimal(vector<string>& vec){
    int len = vec.size();
    int ans = 0;
    for(int i = 0; i < len; ++i){
        ans += mp[vec[i]];
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    mp["tret"] = 0, mp["jan"] = 1, mp["feb"] = 2, mp["mar"] = 3, mp["apr"] = 4, mp["may"] = 5, mp["jun"] = 6,
    mp["jly"] = 7, mp["aug"] = 8, mp["sep"] = 9, mp["oct"] = 10, mp["nov"] = 11, mp["dec"] = 12;
    mp["tam"] = 13, mp["hel"] = 26, mp["maa"] = 39, mp["huh"] = 52, mp["tou"] = 65, mp["kes"] = 78;
    mp["hei"] = 91, mp["elo"] = 104, mp["syy"] = 117, mp["lok"] = 130, mp["mer"] = 143, mp["jou"] = 156;

    int n;
    string s;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i){
        getline(cin, s);
        stringstream ss(s);
        if(isdigit(s[0])){
            int decimal;
            ss >> decimal;
            cout << toMars(decimal) << endl;
        }else{
            vector<string> mardigit;
            while(ss >> s) mardigit.push_back(s);
            cout << toDecimal(mardigit) << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

/*
3
aaajkhjfffjjj
af
ajkhjfjjj

3
abc_fff__a_sss_t_ttt_fff

5
_____anc
_
_anc

3
bbbavvvb
v
bbbavb

3
caseee1__thiiis_iiisss_a_teeeeeest
ei
case1__this_isss_a_teest
*/

int main()
{
    string str;
    int k;

    cin >> k >> str;
    int n = str.length();
    multimap<char, string> cnt;
    string ans, stuck;
    for(int i = 0; i < n; ++i)
    {
        string sub(str.substr(i, k));
        int ok = 1;
        for(int j = 1; j < k; ++j){
            if(sub[j] != sub[j - 1]){
                ok = 0;
                break;
            }
        }
        cnt.insert(make_pair(str[i], sub));
        if(ok) i += k - 1;  //连续的k的字符则跳过
    }
    for(int i = 0; i < n; ++i)
    {
        auto range = cnt.equal_range(str[i]);
        int ok = 1;
        if(cnt.count(range.first->first) == 1){ //只出现一次的字符
            string tmp = range.first->second;
            //此情况下，只有最后一个且只出现一次的字符，如bbbac，因为前面Insert的缘故，在此特判
            if(tmp.length() == 1) ok = 0;
            for(int j = 1; j < (int)tmp.length(); ++j){
                if(tmp[j] != tmp[j - 1]){
                    ok = 0;
                    break;
                }
            }
        }
        //多次出现的字符
        for(auto it = ++range.first; it != range.second; ++it){
            auto i = it;
            if(it->second != (--i)->second){
                ok = 0;
                break;
            }
        }
        if(!ok){
            ans.push_back(str[i]);
        }
        else{
            int onlyone = 1;
            for(auto j = stuck.begin(); j != stuck.end(); ++j){
                if(str[i] == *j){
                    onlyone = 0;
                    break;
                }
            }
            if(onlyone) stuck.push_back(str[i]);
            ans.push_back(str[i]);
            i += k - 1;
        }
    }
    cout << stuck << endl << ans << endl;
}

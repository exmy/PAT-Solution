#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const int mod  = 1000000007;
const int maxn = 100000 + 3;
int dp[maxn][3];    //长度为i, P, PA, PAT的个数分别为dp[i][0], dp[i][1], dp[i][2]
int cntA[maxn], cntT[maxn]; //第i个字符前'P'的个数，第i个字符后'T'的个数

void solve(string& s){
    int ans = 0;
    if(s[0] == 'P') dp[0][0] = 1;
    for(int i = 1; i < s.length(); ++i){
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if(s[i] == 'P') dp[i][0]++;
        else if(s[i] == 'A') dp[i][1] += dp[i][0];
        else{
            dp[i][2] += dp[i][1];
            ans = (ans + dp[i][2]) % mod;
        }
    }
    cout << ans << endl;
}

void solve1(string& s){
    for(int i = 1; i <= s.length(); ++i){
        cntA[i] = cntA[i - 1];
        if(s[i - 1] == 'P') cntA[i]++;
    }
    for(int i = s.length(); i > 0; --i){
        cntT[i] = cntT[i + 1];
        if(s[i] == 'T') cntT[i]++;
    }
    int ans = 0;
    for(int i = 1; i <= s.length(); ++i){
        if(s[i-1] == 'A') ans = (ans + cntA[i] * cntT[i]) % mod;
    }
    cout << ans << endl;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE
    string s;
    cin >> s;
    solve1(s);
    // solve(s);

    return 0;
}

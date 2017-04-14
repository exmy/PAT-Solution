#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
struct Fraction{
    LL fz, fm;
};

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

Fraction simplify(Fraction A){
    int g = gcd(A.fz, A.fm);
    return Fraction{A.fz / g, A.fm / g};
}

Fraction operator + (Fraction A, Fraction B){
    A = simplify(A), B = simplify(B);
    LL fz = A.fz * B.fm + A.fm * B.fz;
    LL fm = A.fm * B.fm;
    int g = gcd(fz, fm);
    return Fraction{fz / g, fm / g};
}

int n;
vector<Fraction> f;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b; scanf("%d/%d", &a, &b);
        f.push_back(Fraction{a, b});
    }

    Fraction ans = f[0];
    for(int i = 1; i < f.size(); ++i){
        ans = ans + f[i];
    }

    if(ans.fz % ans.fm == 0){
        cout << ans.fz / ans.fm << endl;
    }else if(abs(ans.fz) > abs(ans.fm)){
        LL integer = ans.fz / ans.fm;
        ans.fz %= ans.fm;
        if(ans.fm < 0){
            ans.fz = -ans.fz;
            ans.fm = -ans.fm;
        }
        printf("%lld %lld/%lld\n", integer, ans.fz, ans.fm);
    }else{
        printf("%lld/%lld\n", ans.fz, ans.fm);
    }


    return 0;
}

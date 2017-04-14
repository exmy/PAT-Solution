# include <iostream>
# include <list>
# include <cstdio>
# include <cmath>
# include <iomanip>
using namespace std;

struct poly{
    double coef;
    int expn;
    poly(double c, int e):coef(c), expn(e){}
};

list<poly> init(int n)
{
    int e;
    double c;
    list<poly> a;

    for(int i = 0; i < n; ++i)
    {
        cin >> e >> c;
        poly tmp(c, e);
        a.push_back(tmp);
    }
    return a;
}

list<poly> AddPoly(list<poly> &a, list<poly> &b)
{
    list<poly> c;
    list<poly>::iterator pa = a.begin(), pb = b.begin();
    while(pa != a.end() && pb != b.end())
    {
        if(pa->expn < pb->expn){
            poly tmp(pb->coef, pb->expn);
            c.push_back(tmp);
            pb++;
        }
        else if(pa->expn > pb->expn){
            poly tmp(pa->expn, pa->coef);
            c.push_back(tmp);
            pa++;
        }
        else{
            double coef = pa->coef + pb->coef;
            if(fabs(coef) > 1e-6){
                poly tmp(coef, pa->expn);
                c.push_back(tmp);
            }
            pa++;
            pb++;
        }
    }
    for(; pa != a.end(); pa++){ c.push_back(*pa); }
    for(; pb != b.end(); pb++){ c.push_back(*pb); }
    return c;
}

int main()
{
    int n;

    cin >> n;
    list<poly> a = init(n);
    cin >> n;
    list<poly> b = init(n);

    list<poly> c = AddPoly(a, b);

    cout << c.size();
    cout << fixed << setprecision(1);
    for(list<poly>::iterator it = c.begin(); it != c.end(); ++it)
    {
        //printf(" %d %.1f", it->expn, it->coef);
        cout << " " << it->expn << " " << it->coef;
    }
    cout << endl;
}

//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <regex>
//#include <cstdlib>
//using namespace std;
//
//const int maxn = 100 + 5;
//int n, k;
//string s;
//
//int main(){
//#ifdef EXMY
//freopen("data.in", "r", stdin);
//#endif // EXMY
//
//    cin >> n;
//    double sum = 0, t;
//    regex e("-?[0-9]{0,4}(.[0-9]{0,2})?");
//    for(int i = 0; i < n; ++i){
//        cin >> s;
//        if(regex_match(s, e) && fabs(t = atof(s.c_str())) <= 1000){
//            sum += t;
//            k++;
//        }
//        else{
//            printf("ERROR: %s is not a legal number\n", s.c_str());
//        }
//    }
//    if(k == 0){
//        printf("The average of 0 numbers is Undefined\n");
//    }else{
//        printf("The average of %d numbers is %.2f\n", k, sum / k);
//    }
//
//    return 0;
//}


#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

char s[1000];
int n;
int num,num2,pos;

bool f() {
    int p=0;
    for(int i=0; s[i]; i++) {
        if(s[i]>='0'&&s[i]<='9') continue;
        else if(i==0&&s[i]=='-') continue;
        else if(s[i]=='.') {
            p++;
            continue;
        } else return 0;
    }

    if(p>1) return 0;

    pos=strlen(s);
    for(int i=0; s[i]; i++) if(s[i]=='.') pos=i;

    int hh=strlen(s)-pos-1;
    if(hh>2) return 0;

    num=0;
    for(int i=0; i<pos; i++) {
        if(s[i]>='0'&&s[i]<='9')
            num=num*10+s[i]-'0';
        if(num>1000) return 0;
    }
    if(num>1000) return 0;

    num2=0;
    for(int i=pos+1; s[i]; i++)
        num2=num2*10+s[i]-'0';

    double a=1.0*num+num2/(pow(10.0,strlen(s)-pos-1));
    if(a>1000.0) return 0;

    return 1;
}

int main() {
    scanf("%d",&n);
    double sum=0;
    int  geshu=0;
    for(int i=1; i<=n; i++) {
        scanf("%s",s);
        if(f()==0)
            printf("ERROR: %s is not a legal number\n",s);
        else {
            double a=0;
            a=1.0*num+num2/(pow(10.0,strlen(s)-pos-1));
            if(s[0]=='-') a=-a;
            sum=sum+a;
            geshu++;
        }
    }
    if(geshu==1)
        printf("The average of 1 number is %.2lf\n",sum);
    else if(geshu==0)
        printf("The average of 0 numbers is Undefined\n");
    else
        printf("The average of %d numbers is %.2lf\n",geshu,sum/geshu);
    return 0;
}

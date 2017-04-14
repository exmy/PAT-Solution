#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Student{
    string name;
    int height;
    Student(){}
    Student(string n, int h):name(n), height(h){}
};
vector<Student> vec;
int n, k;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n >> k;
    string s;
    int h;
    for(int i = 0; i < n; ++i){
        cin >> s >> h;
        vec.push_back(Student(s, h));
    }

    sort(vec.begin(), vec.end(), [](Student s1, Student s2){
         if(s1.height != s2.height) return s1.height > s2.height;
         return s1.name < s2.name;
          });

    int rows = n / k;
    deque<Student> Q;
    int i = 0;
    for(i = 0; i < rows + n % k; ++i){
        if(i & 1) Q.push_front(vec[i]);
        else Q.push_back(vec[i]);
    }
    for(int j = 0; j < Q.size(); ++j){
        if(j) cout << " ";
        cout << Q[j].name;
    }
    cout << endl;

    for(int j = 0; j < k - 1; ++j){
        Q.clear();
        int t = i;
        bool flag = true;
        for(; i < t + rows; ++i){
            if(flag){
                Q.push_back(vec[i]);
                flag = !flag;
            }else{
                Q.push_front(vec[i]);
                flag = !flag;
            }
        }
        for(int x = 0; x < Q.size(); ++x){
            if(x) cout << " ";
            cout << Q[x].name;
        }
        cout << endl;
    }

    return 0;
}

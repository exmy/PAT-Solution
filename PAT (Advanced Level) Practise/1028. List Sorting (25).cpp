#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 100000 + 10;
struct Student{
    string ID;
    string name;
    int score;

    Student(){}
    Student(string id, string n, int s):ID(id), name(n), score(s){}
};

int   n, c;
Student stu[maxn];

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
#endif // LOCAL

    cin >> n >> c;
    char id[10], name[10];
    int score;

    for(int i = 0; i < n; ++i){
//        cin >> stu[i].ID >> stu[i].name >> stu[i].score;
        scanf("%s %s %d", id, name, &score);
        stu[i] = Student(id, name, score);
    }

    if(c == 1){
        sort(stu, stu + n, [](Student& s1, Student& s2){ return s1.ID < s2.ID; });
    }
    else if(c == 2){
        sort(stu, stu + n, [](Student& s1, Student& s2){
                if(s1.name != s2.name) return s1.name < s2.name;
                else return s1.ID < s2.ID;
             });
    }
    else{
        sort(stu, stu + n, [](Student& s1, Student& s2){
                if(s1.score != s2.score) return s1.score < s2.score;
                else return s1.ID < s2.ID;
             });
    }
    for(int i = 0; i < n; ++i){
//        cout << stu[i].ID << " " << stu[i].name << " " << stu[i].score << endl;
        printf("%s %s %d\n", stu[i].ID.c_str(), stu[i].name.c_str(), stu[i].score);
    }

    return 0;
}

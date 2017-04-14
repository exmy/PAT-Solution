#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 10000 + 10;
struct Book{
    string ID, title, author, publisher, pubyear;
    string keywords;
    Book(){}
    Book(string id, string t, string a, string keys, string p, string y):
        ID(id), title(t), author(a), keywords(keys), publisher(p), pubyear(y){}
};

int n, m;
Book books[maxn];

void solve(){

    sort(books, books + n, [](Book& b1, Book& b2){ return b1.ID < b2.ID; });

    cin >> m;
    string query;
    cin.ignore();
    for(int i = 0; i < m; ++i){
        getline(cin, query);
        cout << query << endl;
        string s = query.substr(3);
        switch(query[0]){
            case '1':{
                bool flag = false;
                for(int i = 0; i < n; ++i){
                    if(s == books[i].title){
                        flag = true;
                        cout << books[i].ID << endl;
                    }
                }
                if(!flag) cout << "Not Found" << endl;
                break;
            }
            case '2':{
                bool flag = false;
                for(int i = 0; i < n; ++i){
                    if(s == books[i].author){
                        flag = true;
                        cout << books[i].ID << endl;
                    }
                }
                if(!flag) cout << "Not Found" << endl;
                break;
            }
            case '3':{
                bool flag = false;
                for(int i = 0; i < n; ++i){
                    if(books[i].keywords.find(s) != string::npos){
                        flag = true;
                        cout << books[i].ID << endl;
                    }
                }
                if(!flag) cout << "Not Found" << endl;
                break;
            }
            case '4':{
                bool flag = false;
                for(int i = 0; i < n; ++i){
                    if(s == books[i].publisher){
                        flag = true;
                        cout << books[i].ID << endl;
                    }
                }
                if(!flag) cout << "Not Found" << endl;
                break;
            }
            case '5':{
                bool flag = false;
                for(int i = 0; i < n; ++i){
                    if(s == books[i].pubyear){
                        flag = true;
                        cout << books[i].ID << endl;
                    }
                }
                if(!flag) cout << "Not Found" << endl;
                break;
            }
        }
    }

}

int main(){
#ifdef LOCAL
freopen("data.in", "r", stdin);
#endif // LOCAL

    cin >> n;
    string info[6];
    cin.ignore();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 6; ++j) getline(cin, info[j]);
        books[i] = Book(info[0], info[1], info[2], info[3], info[4], info[5]);
    }

    solve();

    return 0;
}

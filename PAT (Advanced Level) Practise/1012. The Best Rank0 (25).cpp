#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 2000 + 10;

struct STU{
	string id;
	int acme[4];
	STU(){}
	STU(string _id, int c, int m, int e):id(_id)
		{ acme[0] = c + m + e, acme[1] = c, acme[2] = m, acme[3] = e; }
};

struct Rank{
	int rank[4];
	char rankof[4];
};

int   n, m;
STU   stu[maxn];
map<string, Rank> rankList;
char priority[] = {'A', 'C', 'M', 'E'};

void solve(){

    for(int k = 0; k < 4; ++k){
        sort(stu, stu + n, [k](STU& s1, STU& s2){ return s1.acme[k] > s2.acme[k]; });
        rankList[stu[0].id].rank[k] = 1;
        rankList[stu[0].id].rankof[k] = priority[k];
        int interval = 1;
        for(int i = 1; i < n; ++i){
            if(stu[i].acme[k] == stu[i - 1].acme[k]){
                rankList[stu[i].id].rank[k] = rankList[stu[i - 1].id].rank[k];
                interval++;
            }
            else{
                rankList[stu[i].id].rank[k] = rankList[stu[i - 1].id].rank[k] + interval;
                interval = 1;
            }
            rankList[stu[i].id].rankof[k] = priority[k];
        }
    }

	string id;
	for(int i = 0; i < m; ++i){
		cin >> id;
		bool flag = false;
		for(int i = 0; i < n; ++i){
			if(id == stu[i].id){
                int idx = 0, m = rankList[id].rank[0];
                for(int j = 1; j < 4; ++j){
                    if(m > rankList[id].rank[j]){
                        idx = j;
                        m = rankList[id].rank[j];
                    }
                }
				printf("%d %c\n", m, rankList[id].rankof[idx]);
				flag = true;
				break;
			}
		}
		if(!flag) printf("N/A\n");
	}
}

int main(){
#ifdef LOCAL
freopen("data.in", "r", stdin);
#endif

	cin >> n >> m;
	string id;
	int c, m, e;
	for(int i = 0; i < n; ++i){
		cin >> id >> c >> m >> e;
		stu[i] = STU(id, c, m, e);
	}

	solve();

	return 0;
}

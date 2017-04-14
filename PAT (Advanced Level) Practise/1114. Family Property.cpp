#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 10005;
struct Person{
    int m_esate;
    int area;
};
struct Ans_info{
    int id, m;
    double avg_sets, avg_area;
};
Person p_info[maxn];
int p[maxn];
bool flag[maxn];
int n;

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void Union(int x, int y){
    x = find(x), y = find(y);
    if(x != y){
        p[x] = y;
    }
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    for(int i = 0; i < maxn; ++i) p[i]= i;

    cin >> n;
    int id, f_id, m_id, k, kid;
    for(int i = 0; i < n; ++i){
        cin >> id >> f_id >> m_id >> k;
        flag[id] = flag[f_id] = flag[m_id] = true;
        if(f_id != -1) Union(id, f_id);
        if(m_id != -1) Union(id, m_id);
        for(int j = 0; j < k; ++j){
            cin >> kid;
            flag[kid] = true;
            Union(id, kid);
        }
        cin >> p_info[id].m_esate >> p_info[id].area;
    }
    // the root id of every family
    vector<int> roots;
    for(int i = 0; i < maxn; ++i){
        if(flag[i] && find(i) == i) roots.push_back(i);
    }
    vector<Ans_info> vec;
    for(auto root : roots){
        int tot_esate = 0, tot_area = 0, tot_m = 0;
        id = root;
        for(int i = 0; i < maxn; ++i){
            // if i is the member of the family
            if(flag[i] && find(i) == root){
                id = min(id, i);
                tot_m++;
                tot_area += p_info[i].area;
                tot_esate += p_info[i].m_esate;
            }
        }
        vec.push_back(Ans_info{id, tot_m, 1.0*tot_esate/tot_m, 1.0*tot_area/tot_m});
    }

    sort(vec.begin(), vec.end(), [](Ans_info a1, Ans_info a2){
            if(a1.avg_area != a2.avg_area) return a1.avg_area > a2.avg_area;
            return a1.id < a2.id;
         });

    cout<< vec.size() << endl;
    for(int i = 0; i < vec.size(); ++i){
        printf("%04d %d %.3f %.3f\n", vec[i].id, vec[i].m, vec[i].avg_sets, vec[i].avg_area);
    }
    return 0;
}

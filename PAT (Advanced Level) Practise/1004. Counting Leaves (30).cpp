# include <iostream>
# include <cstdio>
# include <vector>
# include <queue>
using namespace std;

vector< vector<int> > edge;             //使用邻接表存储

//需要知道什么时候一层遍历完
vector<int> countLeaves(int s)
{
    vector<int> res;
    queue<int> Q;
    int last = s, tail = 0;

    Q.push(s);
    int cnt = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        if(edge[u].size() == 0) cnt++;
        for(size_t i = 0; i < edge[u].size(); ++i)
        {
            int v = edge[u][i];
            Q.push(v);
            tail = v;                   //key

        }
        if(u == last){                  //一层遍历完
            res.push_back(cnt);
            cnt = 0;
            last = tail;                //update
        }
    }
    return res;
}

int main()
{
    int n, m, id, k, v;

    cin >> n >> m;
    edge.resize(n + 1);
    while(m--)
    {
        cin >> id >> k;
        while(k--)
        {
            cin >> v;
            edge[id].push_back(v);
        }
    }

    vector<int> res = countLeaves(1);
    for(size_t i = 0; i < res.size(); ++i)
    {
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}

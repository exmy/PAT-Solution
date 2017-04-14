#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int G[1300][130][70];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
bool vis[1300][130][70];
int N, M, L, T;
int cnt;

struct Node{ int x, y, z; };

void dfs(int x, int y, int z){
    vis[x][y][z] = 1;
    cnt++;
    for(int i = 0; i < 6; ++i){
        int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M && 0 <= nz && nz < L && !vis[nx][ny][nz] && G[nx][ny][nz]){
            dfs(nx, ny, nz);
        }
    }
}

void bfs(int x, int y, int z){
    queue<Node> Q;
    Q.push(Node{x, y, z});
    vis[x][y][z] = true;
    while(!Q.empty()){
        Node u = Q.front(); Q.pop();
        cnt++;
        for(int i = 0; i < 6; ++i){
            int nx = u.x + dx[i], ny = u.y + dy[i], nz = u.z + dz[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M && 0 <= nz && nz < L && !vis[nx][ny][nz] && G[nx][ny][nz]){
                vis[nx][ny][nz] = true;
                Q.push(Node{nx, ny, nz});
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> N >> M >> L >> T;
    for(int k = 0; k < L; ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j) cin >> G[i][j][k];
        }
    }

    int ans = 0;
    for(int k = 0; k < L; ++k){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(!vis[i][j][k] && G[i][j][k]){
                    cnt = 0;
                    bfs(i, j, k);
                    if(cnt >= T) ans += cnt;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

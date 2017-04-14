#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, t;
int m, n;
vector<int> a;

int main(){
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), [](int x, int y){return x > y;});
    t = sqrt(N * 1.0);
    for(n = t, m = t; ;){
        int tmp = m * n;
        if(tmp == N) break;
        else if(tmp < N) m++;
        else n--;
    }
    vector<vector<int> > squ(m, vector<int>(n));
    int k = 0;
    int beginX = 0, endX = n - 1;   // column
    int beginY = 0, endY = m - 1;   // row
    while(true){
        // from left to right
        for(int i = beginX; i <= endX; ++i) squ[beginY][i] = a[k++];
        if(++beginY > endY) break;
        // from top to down
        for(int i = beginY; i <= endY; ++i) squ[i][endX] = a[k++];
        if(beginX > --endX) break;
        // from right to left
        for(int i = endX; i >= beginX; --i) squ[endY][i] = a[k++];
        if(beginY > --endY) break;
        // from down to up
        for(int i = endY; i >= beginY; --i) squ[i][beginX] = a[k++];
        if(++beginX > endX) break;
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(j) cout << " ";
            cout << squ[i][j];
        }
        cout << endl;
    }

    return 0;
}

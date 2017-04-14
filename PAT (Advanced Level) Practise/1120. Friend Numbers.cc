#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>
using namespace std;

int n;
set<int> S;

int main()
{
#ifndef ONLINE_JUDGE
freopen("data.in", "r", stdin);
#endif

	cin >> n;
	for(int i = 0; i < n; ++i){
		string t; cin >> t;
		int id = 0;
		for(int j = 0; j < t.length(); ++j) id += t[j] - '0';
		S.insert(id);
	}

	cout << S.size() << endl;
	int i = 0;
	for(set<int>::iterator it = S.begin(); it != S.end(); ++it){
		if(i++) cout << " ";
		cout << *it;
	}

	return 0;
}

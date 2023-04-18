//#include <stdio.h>
//#include <string.h>
//#include <string.h>
//#include <queue>
#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

int parent[100001] = { 0, };
vector<int> v[100001];

void dfs(int cur) {
	for (int i = 0; i < v[cur].size(); i++)
		if (parent[v[cur][i]] == 0) {
			parent[v[cur][i]] = cur;
			dfs(v[cur][i]);
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N = 0;
	int t1, t2;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}

	dfs(1);
	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

}

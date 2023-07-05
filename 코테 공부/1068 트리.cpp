#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int ans = 0,banned = 0;
vector<int> tree[51];

void dfs(int node) {
	if (tree[node].size() == 0) {
		ans++;
		return;
	}
	for (int i : tree[node]) {
		dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int arr[51];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> banned;
	int root = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == -1) {
			root = i; 
			if (banned == i) {
				cout << 0;
				return 0;
			}
			continue;
		}
		if (i != banned) {
			tree[arr[i]].push_back(i);
		}
	}
	if (banned == root) {
		cout << 0;
		return 0;
	}
	dfs(root);
	cout << ans;
}
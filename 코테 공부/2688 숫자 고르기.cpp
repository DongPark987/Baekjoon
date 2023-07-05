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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int arr[101];
	int visit[101] = { 0, };
	vector<int> ans;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		int cur = i;
		visit[cur]++;
		while (true) {
			cur = arr[cur];
			visit[cur]++;
			if (visit[cur] >= 2)break;
		}
		if (visit[i] == 2) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << "\n";
	}


}
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

bool cmp(pair<int, int>A, pair<int,int> B) {
	return A.first < B.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T = 0; 
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		pair<int, int> v[100001];
		int N; 
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}

		sort(v, v + N, cmp);
		int Min = 1000000;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (v[i].second < Min) {
				ans++;
				Min = (Min < v[i].second) ? Min : v[i].second;
			}
		}
		cout << ans << '\n';
	}
}
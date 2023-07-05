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

bool cmp(pair<int, int>A, pair<int, int>B) {
	return A.first < B.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int dp[101] = { 0, };
	cin >> N;
	pair<int, int> line[101];
	for (int i = 0; i < N; i++) {
		cin >> line[i].first >> line[i].second;
	}
	sort(line, line + N, cmp);

	int Max = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (line[i].second > line[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
				Max = max(Max, dp[i]);
			}
		}
	}
	cout << N - (Max + 1);
}
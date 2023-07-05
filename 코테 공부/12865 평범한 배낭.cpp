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

int dp[101][100000] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, K, ans = 0;
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		int tw, tv;
		cin >> tw >> tv;
		for (int j = 0; j <= K; j++) {
			if (tw > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - tw] + tv, dp[i - 1][j]);
				ans = max(dp[i][j], ans);
			}
		}
	}
	cout << ans;
}
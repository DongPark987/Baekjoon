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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int data[201];
	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}

	int ans = 0;
	int dp[201] = { 0, };
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (data[j] < data[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}
	cout << N - (ans + 1);
}
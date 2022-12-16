/*

//#include <stdio.h>
//#include <stack>
#include <string.h>
//#include <queue>
//#include <vector>
#include <iostream>
//#include <string>
//#include <deque>
#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

int N;
int a[2001];
int dp[2001][2001];

int rec(int l, int r, int d) {
	
	if (l > r) return 0;
	
	int& ret = dp[l][r];
	if (ret != -1) {
		
		return ret;
	}
	ret = max(a[l] * d + rec(l + 1, r, d + 1), a[r] * d + rec(l, r - 1, d + 1));
	cout << "[" << l << ", " << r <<"|"<<d << "]: " << ret << endl;

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	cout << rec(0, N - 1, 1);
}

*/
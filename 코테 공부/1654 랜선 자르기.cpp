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


int line[10001] = { 0, };
int N, K;
long long L, R, ans = 1;


int check(long long mid) {
	//cout << "mid: " << mid << endl;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		sum += line[i] / mid;
		if (sum >= N) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> line[i];
	L = 1;
	R = 2147483647;

	while (L <= R) {
		//cout << "(" << L << ", " << R << ")\n";
		long long mid = (L + R) / 2;
		if (check(mid)) {
			L = mid + 1;
			ans = mid;
		}
		else {
			R = mid - 1;
		}
	}
	cout << ans;
}
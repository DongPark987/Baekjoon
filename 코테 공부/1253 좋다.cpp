#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;
#pragma warning(disable : 4996)

int arr[2001];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int zero = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == 0)zero++;
	}
	sort(arr, arr + N);
	int ans = 0;

	for (int cur = 0; cur < N; cur++) {
		int L = 0, R = N - 1;
		int target = arr[cur];
		while (L < R) {
			if (L == cur) {
				L++;
				continue;
			}
			if (R == cur) {
				R--;
				continue;
			}

			if (arr[L] + arr[R] == target) {
				ans++;
				break;
			}

			if (arr[L] + arr[R] < target)
				L++;
			else
				R--;
		}
	}
	cout << ans;
}
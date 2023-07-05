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
#pragma warning(disable : 4996)

int N, M;
int arr[500001];

int upper(int t) {
	int L = 0, R = N - 1, M;
	while (L < R) {
		M = (L + R) / 2;
		if (arr[M] <= t) {
			L = M + 1;
		}
		else {
			R = M;
		}
	}
	return R;
}

int lower(int t) {
	int L= 0, R=N-1, M;
	while (L < R) {
		M = (L + R) / 2;
		if (arr[M] < t) {
			L = M + 1;
		}
		else {
			R = M;
		}
	}
	return R;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	sort(arr, arr + N);

	cin >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		int up = upper(tmp);
		int lo = lower(tmp);
		if (arr[up] == tmp && up == N - 1) {
			cout << up - lo + 1 << " ";
		}
		else {
			cout << up - lo << " ";
		}
	}
}
//#include <stdio.h>
//#include <stack>
//#include <string.h>
//#include <queue>
//#include <vector>
#include <iostream>
#include <deque>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

int arr[500001] = { 0, };
int tmp[500001] = { 0, };
int N, K, cnt = 0;

void merge(int l, int m, int r);
void merge_sort(int l, int r) {

	if (l < r) {
		int m = (l + r) / 2;
		merge_sort(l, m);
		merge_sort(m + 1, r);
		merge(l, m, r);
	}
}

void merge(int l, int m, int r) {

	int i = l, j = m + 1, t = l;
	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) 
			tmp[t++] = arr[i++];
		else 
			tmp[t++] = arr[j++];
	}
	while (i <= m)
		tmp[t++] = arr[i++];

	while (j <= r)
		tmp[t++] = arr[j++];

	for (int i = l; i <= r; i++) {
		arr[i] = tmp[i];
		if (++cnt == K) {
			cout << tmp[i];
			exit(0);
		}
	}
}


int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	merge_sort(1, N);

	cout << -1;
}
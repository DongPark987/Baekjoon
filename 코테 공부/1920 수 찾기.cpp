//#include <stdio.h>
//#include <stack>
//#include <string.h>
//#include <queue>
//#include <vector>
#include <iostream>
//#include <string>
//#include <deque>
#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

#define Max 100001

int N, M;
int A[Max];

int binarySearch(int size, int target) {
	int start = 0;
	int end = size - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (A[mid] == target) return 1;
		else if (A[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}



int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> M;

	sort(A, A + N);

	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << binarySearch(N, tmp) << "\n";
	}
}
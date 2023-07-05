#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>

using namespace std;
int N;
int cnt = 9;
int num[10];
int len;

void backtrack(int loc, int top) {
	if (loc == 0) {
		cnt++;
		if (cnt == N) {
			for (int i = len - 1; i >= 0; i--) {
				cout << num[i];
			}
			exit(0);
		}
		return;
	}
	for (int i = 0; i <= top; i++) {
		num[loc - 1] = i;
		backtrack(loc - 1, i - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	if (N < 10) {
		cout << N;
		return 0;
	}

	for (int i = 2; i <= 10; i++) {
		len = i;
		backtrack(i, 9);
	}
	cout << -1;
}
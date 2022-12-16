//#include <stdio.h>
//#include <string.h>
//#include <queue>
#include <iostream>

using namespace std;
#pragma warning(disable : 4996)

int n = 0, ans[3] = { 0, };
int board[2188][2188] = { 0, };

bool check(int N, int x, int y) {
	int start = board[y][x];
	for (int i = y; i < y + N; i++) 
		for (int j = x; j < x + N; j++) 
			if (start != board[i][j]) 
				return false;

	return true;
}

void rec(int N, int x, int y) {
	if (check(N, x, y)) {
		ans[board[y][x] + 1]++;
		return;
	}
	else {
		int div = N / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				rec(div, x + j * div, y + i * div);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	//mprint();
	rec(n, 0, 0);
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n";
	}
}
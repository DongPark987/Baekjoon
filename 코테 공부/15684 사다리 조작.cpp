#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool Map[31][31] = {false,};
bool visit[31][31] = { false, };
int N, M, H;

bool check(int n) {
	int cur = n;
	for (int i = 1; i < M + 1; i++) {
		if (Map[i][cur - 1]) {
			cur--;
		}
		else if (Map[i][cur]) {
			cur++;
		}
	}

	if (cur == n) {
		return true;
	}
	else {
		return false;
	}
}

void backtrack(int depth, int max) {
	if (depth == max) {
		for (int i = 1; i <= N; i++) {
			if (check(i) == false) {
				return;
			}
		}
		cout << depth;
		exit(0);
	}

	for (int j = 1; j <= M; j++) {
		for (int i = 1; i < N; i++) {
			if (visit[j][i] == false && Map[j][i] == false && Map[j][i - 1] == false && Map[j][i + 1] == false) {
				Map[j][i] = true;
				backtrack(depth + 1, max);
				Map[j][i] = false;
				if (depth == 0) {
					visit[j][i] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> H >> M;

	for (int i = 0; i < H; i++) {
		int tx, ty;
		cin >> ty >> tx;
		Map[ty][tx] = true;
	}

	for (int i = 0; i <= 3; i++) {
		backtrack(0, i);
		for (int j = 1; j <= M; j++)memset(visit[j], 0, sizeof(bool) * N);
	}
	cout << -1;
}
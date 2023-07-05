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

int N, M,K;
int board[12][12] = { 0, };
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
bool visit[12][12] = { 0, };
int Max = -10000000;

void backtrack(int loc, int sum, int x, int y) {
	if (loc == K) {
		Max = max(Max, sum);
		return;
	}
	for (int i = y; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visit[i][j] == 0) {
				bool check = false;
				for (int k = 0; k < 4; k++) {
					int tx = j + dx[k], ty = i + dy[k];
					if (visit[ty][tx] == true) {
						check = true;
						break;
					}
				}
				if (check == false) {
					visit[i][j] = true;
					backtrack(loc + 1, sum + board[i][j], j, i);
					visit[i][j] = false;
				}
			}

		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	backtrack(0, 0, 1, 1);

	cout << Max;
}
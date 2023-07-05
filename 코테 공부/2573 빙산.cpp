#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
//N: За, M: ї­
int N, M;
int sea[301][301] = { 0, };
bool visit[301][301] = { false, };

bool check(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N)return false;
	return true;
}

void melt() {
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (sea[i][j] != 0) {
				visit[i][j] = true;
				for (int k = 0; k < 4; k++) {
					int ty = i + dy[k], tx = j + dx[k];
					if (check(tx, ty) && sea[ty][tx] == 0 && visit[ty][tx] == false) {
						if (sea[i][j] == 0)break;
						sea[i][j]--;
					}
				}
			}
		}
	}
}

int count() {
	memset(visit, false, sizeof(visit));
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (sea[y][x] != 0 && visit[y][x] == false) {
				cnt++;
				queue<pair<int, int>> q;
				visit[y][x] = true;
				q.push({ x,y });
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int tx = x + dx[i], ty = y + dy[i];
						if (check(tx, ty) && sea[ty][tx] != 0 && visit[ty][tx] == false) {
							visit[ty][tx] = true;
							q.push({ tx,ty });
						}
					}
				}
			}
		}
	}
	return cnt;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << sea[i][j]<<" ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> sea[i][j];
		}
	}
	//cout << endl;
	for (int i = 1; i < 10000; i++) {
		melt();
		//print();
		int ans = count();
		//cout << ans << endl;
		if (ans == 0) {
			cout << 0;
			exit(0);
		}
		if (ans	>= 2) {
			cout << i;
			exit(0);
		}
	}

}
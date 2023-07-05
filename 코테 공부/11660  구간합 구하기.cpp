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
int board[1025][1025] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			board[i][j] = board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1] + board[i][j];
			//cout << board[i][j] << endl;
		}
	}

	for (int i = 0; i < M; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << board[y2][x2] - board[y2][x1 - 1] - board[y1 - 1][x2] + board[y1 - 1][x1 - 1]<<"\n";
	}
}
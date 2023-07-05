#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

struct piece
{
	int x, y, d;
};

vector<piece> p;
char map[13][13];
int board[13][13][4] = {0,};
int N, K;
int dx[4] = { 1,-1,0,0 }, dy[4] = {0, 0, -1, 1};
int cd[4] = { 1,0,3,2 };
int ans = 0;

int FindFloor(int i) {
	int x = p[i].x, y = p[i].y;
	int floor = 0;
	while (board[y][x][floor] != i) 
		floor++;
	return floor;
}

void StackUp(vector<int> v, int x, int y) {
	int top = 0;
	while (board[y][x][top] != 0)top++;
	for (int i = 0; i < v.size(); i++) {
		if (top == 3) {
			printf("%d", ans);
			exit(0);
		}
		board[y][x][top] = v[i];
		top++;
	}
}

void StackErase(int floor,int size, int x, int y) {
	for (int i = 0; i < size; i++) {
		board[y][x][floor] = 0;
		floor++;
	}
}

bool check(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) 
		return false;
	else 
		return true;
}

void red(int n) {
	vector<int> v;

	int x = p[n].x, y = p[n].y, d = p[n].d;
	int tx = x + dx[d], ty = y + dy[d];
	int floor = FindFloor(n);

	for (int i = 0; i < K; i++) {
		if (board[y][x][i + floor] != 0) {
			v.push_back(board[y][x][i + floor]);
			p[board[y][x][i + floor]].x = tx;
			p[board[y][x][i + floor]].y = ty;
		}
		else {
			break;
		}
	}
	reverse(v.begin(), v.end());
	StackErase(floor, v.size(), x, y);
	StackUp(v, tx, ty);
}

void white(int n) {
	vector<int>v;

	int x = p[n].x, y = p[n].y, d = p[n].d;
	int tx = x + dx[d], ty = y + dy[d];
	int floor = FindFloor(n);

	for (int i = 0; i < K; i++) {
		if (board[y][x][i + floor] != 0) {
			v.push_back(board[y][x][i + floor]);
			p[board[y][x][i + floor]].x = tx;
			p[board[y][x][i + floor]].y = ty;
		}
		else {
			break;
		}
	}

	StackErase(floor, v.size(), x, y);
	StackUp(v, tx, ty);
}

void blue(int n) {
	p[n].d = cd[p[n].d];
	int x = p[n].x, y = p[n].y, d = p[n].d;
	int tx = x + dx[d], ty = y + dy[d];
	if (!check(tx, ty) || map[ty][tx] == '2') {
		return;
	}
	else if (map[ty][tx] == '1') {
		red(n);
	}
	else {
		white(n);
	}
}

void move(int i) {
	int d = p[i].d;
	int tx = p[i].x + dx[d], ty = p[i].y + dy[d];

	if (!check(tx, ty) || map[ty][tx] == '2') {
		blue(i);
	}
	else if (map[ty][tx] == '1') {
		red(i);
	}
	else {
		white(i);
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf(" %c", &map[i][j]);
	
	p.push_back({ 0,0,0 });
	for (int i = 0; i < K; i++) {
		int tx, ty, td;
		scanf("%d %d %d", &ty, &tx, &td);
		p.push_back({ tx-1, ty-1, td-1 });
		board[ty - 1][tx - 1][0] = i + 1;
	}

	for (ans = 1; ans <= 1000; ans++) {

		for (int i = 1; i <= K; i++) {
			move(i);
		}
	}
	printf("-1");
}
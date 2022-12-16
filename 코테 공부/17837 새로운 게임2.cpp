//#include <stdio.h>
////#include <string.h>
////#include <queue>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//#pragma warning(disable : 4996)
//
//struct mPiece {
//	int x, y, d, up = 0, down = 0;
//};
//
//mPiece p[13];
//int board[13][13];
//int piece[13][13] = { 0, };
//int dx[5] = { 0,1,-1,0,0 }, dy[5] = { 0, 0,0,-1,1 }, cd[5] = { 0,2,1,4,3 };
//int N, K, Round = 0;
//
//void mprint() {
//	cout << "\n=================\n";
//	for (int i = 1; i < N + 1; i++) {
//		for (int j = 1; j < N + 1; j++) {
//			cout << piece[i][j] << " ";
//		}
//		cout << endl;
//	}
//	/*int cur = 2;
//	while (cur != 0) {
//		cout << cur << " ";
//		cur = p[cur].up;
//	}
//	cout << endl << "[d:" << p[4].d << endl;*/
//	cout << "=================\n";
//	for (int i = 1; i <= K; i++) {
//		cout << i << ":[x: " << p[i].x << " y:" << p[i].y << " down:" << p[i].down << " up:" << p[i].up << " d:" << p[i].d << "]\n";
//	}
//	cout << "=================\n";
//}
//
//void printp() {
//
//}
//
//void reverse(int n) {
//	int cur = n;
//	int t_down = p[n].down;
//	p[n].down = 0;
//	//cout << t_down << " " << p[n].up << endl;
//	while (true) {
//		swap(p[cur].down, p[cur].up);
//		if (p[cur].down == 0) {
//			p[cur].down = t_down;
//			piece[p[cur].y][p[cur].x] = cur;
//			break;
//		}
//		else
//			cur = p[cur].down;
//	}
//}
//
//void white(int n) {
//	int td = p[n].d;
//	int tx = p[n].x + dx[td], ty = p[n].y + dy[td];
//	int cur = 0;
//	int cnt = 0;
//
//	if (p[n].down == 0)
//		piece[p[n].y][p[n].x] = 0; //ÀÖ´øÀÚ¸® ºñ¿ì±â
//	else
//		p[p[n].down].up = 0; //¾Æ·¡¿Í ¿¬°á ²÷±â
//
//	p[n].down = 0;
//	if (piece[ty][tx]) {
//		cur = piece[ty][tx];
//		while (p[cur].up != 0) {
//			cnt++;
//			cur = p[cur].up;
//		}
//		cnt++;
//		p[cur].up = n;
//		p[n].down = cur;
//	}
//	else {
//		piece[ty][tx] = n;
//	}
//	cur = n;
//	while (cur != 0) {
//		cnt++;
//		p[cur].x = tx;
//		p[cur].y = ty;
//		cur = p[cur].up;
//	}
//	//cout << "<" << cnt << ">" << endl;
//	if (cnt >= 4) {
//		cout << Round;
//		exit(0);
//	}
//}
//
//void red(int n) {
//	white(n);
//	reverse(n);
//}
//
//void blue(int n) {
//	p[n].d = cd[p[n].d];
//	int tx = p[n].x + dx[p[n].d];
//	int ty = p[n].y + dy[p[n].d];
//	if (board[ty][tx] == 0) {
//		//Èò»ö
//		white(n);
//	}
//	else if (board[ty][tx] == 1) {
//		//»¡°­
//		red(n);
//	}
//}
//
//
//int move() {
//	for (int i = 1; i <= K; i++) {
//		int tx = p[i].x + dx[p[i].d];
//		int ty = p[i].y + dy[p[i].d];
//
//		if (board[ty][tx] == 0) {
//			//Èò»ö
//			white(i);
//		}
//		else if (board[ty][tx] == 1) {
//			//»¡°­
//			red(i);
//		}
//		else {
//			//ÆÄ¶û
//			blue(i);
//		}
//
//	}
//	return 0;
//}
//
////0:Èò»ö, 1: »¡°­, 2:ÆÄ¶û
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> N >> K;
//	for (int i = 0; i <= N + 1; i++)
//		for (int j = 0; j <= N + 1; j++)
//			board[i][j] = 2;
//
//	for (int i = 1; i <= N; i++)
//		for (int j = 1; j <= N; j++)
//			cin >> board[i][j];
//
//	for (int i = 1; i <= K; i++) {
//		cin >> p[i].y >> p[i].x >> p[i].d;
//		piece[p[i].y][p[i].x] = i;
//	}
//	//mprint();
//	for (Round = 1; Round <= 1000; Round++) {
//		move();
//		//mprint();
//	}
//	cout << -1;
//}
////#include <stdio.h>
////#include <string.h>
//#include <queue>
////#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//#pragma warning(disable : 4996)
//
//int N, M;
//int board[51][51];
//int ans = 0;
//int visit[51][51];
//int dx[8] = { 0,0,1,-1,1,1,-1,-1 }, dy[8] = { 1,-1,0,0,-1,1,1,-1 };
//
//void bfs(int y, int x) {
//
//    int cnt = 0;
//    queue<pair<int, int>> q;
//    q.push({ y,x });
//    while (!q.empty())
//    {
//        cnt++;
//        int size = q.size();
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < 8; j++) {
//                int tx = q.front().second + dx[j];
//                int ty = q.front().first + dy[j];
//                
//                if (tx < 0 || ty < 0 || tx >= M || ty >= N)
//                    continue;
//
//                if (visit[ty][tx] > cnt) {
//                    visit[ty][tx] = cnt;
//                    q.push({ ty,tx });
//                }
//            }
//            q.pop();
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//    queue<pair<int, int>> q;
//
//    cin >> N >> M;
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < M; j++)
//            visit[i][j] = 99999;
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cin >> board[i][j];
//            if (board[i][j] == 1) {
//                visit[i][j] = 0;
//                q.push({ i,j });
//            }
//        }
//    }
//
//    while (!q.empty()) {
//        bfs(q.front().first, q.front().second);
//        q.pop();
//    }
//
//    int ans = 0;
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < M; j++)
//            ans = max(ans, visit[i][j]);
//    cout << ans;
//}
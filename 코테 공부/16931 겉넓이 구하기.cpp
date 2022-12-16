//#include <stdio.h>
////#include <string.h>
////#include <queue>
////#include <vector>
////#include <iostream>
////#include <algorithm>
//
//using namespace std;
//#pragma warning(disable : 4996)
//
//
//
//int main() {
//    /*ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);*/
//
//    int N, M;
//    int cube[101][101];
//    int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
//    int sum = 0;
//    scanf("%d %d", &N, &M);
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < M; j++)
//            scanf("%d", &cube[i][j]);
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            for (int k = 0; k < 4; k++) {
//                int tx = j + dx[k], ty = i + dy[k];
//                if (tx < 0 || ty < 0 || tx >= M || ty >= N)
//                    sum += cube[i][j];
//                else if (cube[ty][tx] < cube[i][j])
//                    sum += (cube[i][j] - cube[ty][tx]);
//            }
//        }
//    }
//    printf("%d", sum + (M * N * 2));
//}
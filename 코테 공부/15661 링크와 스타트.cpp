//#include <stdio.h>
//#include <string.h>
//#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

int board[21][21];
int N, ans = 1000000;
int L[21], R[21];
int lCur = 0, rCur = 0;

void rec(int cur) {
    if (cur == N) {
        int lSum = 0, rSum = 0;

        if (lCur == 0 || rCur == 0)
            return;

        for (int i = 0; i < lCur; i++)
            for (int j = i + 1; j < lCur; j++)
                lSum += (board[L[i]][L[j]] + board[L[j]][L[i]]);

        for (int i = 0; i < rCur; i++)
            for (int j = i + 1; j < rCur; j++)
                rSum += (board[R[i]][R[j]] + board[R[j]][R[i]]);

        ans = min(ans, abs(lSum - rSum));
    }
    else {
        L[lCur] = cur;
        lCur++;
        rec(cur + 1);
        lCur--;
        R[rCur] = cur;
        rCur++;
        rec(cur + 1);
        rCur--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];


    rec(0);
    cout << ans;
}
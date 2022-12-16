//#include <stdio.h>
//#include <string.h>
////#include <string.h>
////#include <queue>
////#include <iostream>
//#include <algorithm>
//
//using namespace std;
//#pragma warning(disable : 4996)
//
//int HP[3] = { 0, };
//int da[6][3] = { {-9,-3,-1},{-9,-1,-3},{-3,-9,-1},{-1,-9,-3},{-3,-1,-9},{-1,-3,-9} };
//int N;
//int dp[61][61][61] = {};
//
//int rec(int n1, int n2, int n3) {
//	if (n1 < 0)return rec(0, n2, n3);
//	if (n2 < 0)return rec(n1, 0, n3);
//	if (n3 < 0)return rec(n1, n2, 0);
//	if (n1 == 0 && n2 == 0 && n3 == 0)
//		return 0;
//
//	int& ans = dp[n1][n2][n3];
//
//	if (ans != -1)
//		return ans;
//	ans = 999999;
//	for (int i = 0; i < 6; i++)
//		ans = min(ans, rec(n1 + da[i][0], n2 + da[i][1], n3 + da[i][2]) + 1);
//
//	return ans;
//}
//
//int main() {
//	/*ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);*/
//
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//		scanf("%d", &HP[i]);
//	memset(dp, -1, sizeof(dp));
//	printf("%d", rec(HP[0], HP[1], HP[2]));
//	return 0;
//}

////#include <stdio.h>
//#include <iostream>
////#include <stack>
////#include <queue>
////#include <vector>
////#include <deque>
////#include <string.h>
////#include <string>
////#include <algorithm>
//
//using namespace std;
//#pragma warning(disable : 4996)
//
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	int n;
//	int arr[51][2] = { 0, };
//	int result[51];
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i][0] >> arr[i][1];
//		result[i] = 1;
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
//				result[i]++;
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//		cout << result[i] << " ";
//}
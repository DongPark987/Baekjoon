//#include <stdio.h>
#include <iostream>
#include <stack>
//#include <queue>
//#include <vector>
//#include <deque>
//#include <string.h>
#include <string>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	int cnt = 0;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cnt;
		cin >> str;
		for (char c : str) {
			for (int j = 0; j < cnt; j++) {
				cout << c;
			}
		}
		cout << "\n";
	}


}

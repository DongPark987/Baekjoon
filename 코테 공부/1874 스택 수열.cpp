//#include <stdio.h>
#include <stack>
//#include <string.h>
//#include <queue>
//#include <vector>
#include <iostream>
#include <string>
//#include <deque>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0, t = 0, cur = 1;
	stack<int> s;
	string ans;
	ans.append("+\n");
	s.push(1);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		while (true) {
			if (s.empty() || s.top() < t) {
				s.push(++cur);
				ans.append("+\n");
			}
			else if (s.top() == t) {
				s.pop();
				ans.append("-\n");
				break;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << ans;
}

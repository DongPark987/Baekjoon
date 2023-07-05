//#include <stdio.h>
#include <iostream>
#include <stack>
//#include <queue>
//#include <vector>
//#include <deque>
//#include <string.h>
//#include <string>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,tmp;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		if (tmp != 0) {
			s.push(tmp);
		}
		else {
			s.pop();
		}
	}

	int ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
}

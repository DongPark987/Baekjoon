#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		string tstr = str;
		stack<char>s;
		for (int j = 0; j < i; j++) {
			s.push(str[j]);
		}
		while (!s.empty())
		{
			tstr.push_back(s.top());
			s.pop();
		}
		string rstr = tstr;
		reverse(rstr.begin(), rstr.end());
		if (tstr == rstr) {
			cout << tstr.length();
			return 0;
		}
	}

}
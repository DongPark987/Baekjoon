#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	int ans = 0;
	int trigger = 1;
	string buff;

	for (int cur = 0; cur <= str.size(); cur++) {
		if (isdigit(str[cur]))
			buff.push_back(str[cur]);
		else {
			ans += stoi(buff) * trigger;
			buff.clear();
			if (str[cur] == '-') 
				trigger = -1;
		}
	}

	cout << ans;
}
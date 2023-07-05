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

int N, all = 0, ans = 1000000;
int arr[11];
int team[11] = { 0, };
bool visit[11] = { false, };
vector<int>node[11];

int check(int sum) {
	//cout << "[" << sum << "]" << endl;
	//¿˚∆¿ √£±‚

	//for (int i = 1; i <= N; i++) {
	//	cout << team[i] << ",  ";
	//}
	//cout << endl;
	int cur;
	bool visit[11] = { 0, };
	for (cur = 1; cur <= N; cur++) {
		if (team[cur] == 1) {
			break;
		}
	}

	int red = 0, blue = 0;
	queue<int> q;
	
	//¿˚∆¿ ∞À¡ı
	q.push(cur);
	visit[cur] = true;
	red += arr[cur];
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i : node[t]) {
			if (team[i] == 1 && visit[i] == false) {
				//cout << "[" << t << ":" << i << "]\n";
				visit[i] = true;
				q.push(i);
				red += arr[i];
			}
		}
	}
	//cout << "sum: " << sum << ", red: " << red << endl;
	if (sum != red)
		return -1;

	//√ª∆¿ ∞À¡ı
	memset(visit, false, sizeof(visit));
	for (cur = 1; cur <= N; cur++) {
		if (team[cur] == 0) {
			break;
		}
	}

	q.push(cur);
	visit[cur] = true;
	blue += arr[cur];
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i : node[t]) {
			if (team[i] == 0 && visit[i] == false) {
				q.push(i);
				visit[i] = true;
				blue += arr[i];
			}
		}
	}

	//cout << "sum: " << sum << ", red: " << red <<", blue: "<<blue << endl;

	if (red + blue == all) {
		return abs(red - blue);
	}
	else {
		return -1;
	}
}

void rec(int loc, int sum) {
	if (loc == N + 1) {
		if (sum == all || sum == 0) {
			return;
		}
		else {
			int result = check(sum);
			//cout << "result:" << result << endl;
			if (result == -1) {
				return;
			}
			else {
				ans = min(ans, result);
			}
		}
		return;
	}

	team[loc] = 1;
	rec(loc + 1, sum + arr[loc]);
	team[loc] = 0;
	rec(loc + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		all += arr[i];
	}

	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int n;
			cin >> n;
			node[i].push_back(n);
		}
	}
	rec(1, 0);
	if (ans == 1000000)
		cout << -1;
	else
		cout << ans << endl;
}
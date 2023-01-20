//#include <stdio.h>
#include <iostream>
//#include <stack>
#include <queue>
#include <vector>
//#include <deque>
//#include <string.h>
//#include <string>
#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

bool visit_tube[1001] = { false, };
vector<int> node[100001];
vector<int> tube[1001];
int N, K, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			int t;
			cin >> t;
			tube[i + 1].push_back(t);
			node[t].push_back(i + 1);
		}
	}

	if (N == 1 && K == 1 && M == 1) {
		cout << 1;
		return 0;
	}

	int distance = 2;
	queue<int> q;
	for (int i : node[1]) {
		q.push(i);
		visit_tube[i] = true;
	}
	
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int cur = q.front();
			q.pop();
			for (int j : tube[cur]) {
				if (j == N) {
					cout << distance << "\n";
					return 0;
				}
				for (int k : node[j]) {
					if (!visit_tube[k]) {
						visit_tube[k] = true;
						q.push(k);
					}
				}
			}
		}
		distance++;
	}
	cout << -1;
}
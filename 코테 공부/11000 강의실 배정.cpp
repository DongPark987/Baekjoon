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
#pragma warning(disable : 4996)

struct myClass {
	int s, e;
};

bool cmp(myClass A, myClass B) {
	return A.s < B.s;
}

myClass c[200001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> c[i].s >> c[i].e;
	}
	sort(c, c + N, cmp);

	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(c[0].e);
	
	for (int i = 1; i < N; i++) {
		if (pq.top() <= c[i].s) {
			while (!pq.empty()) {
				if (pq.top() <= c[i].s) {
					pq.pop();
				}
				else {
					break;
				}
			}
			pq.push(c[i].e);
		}
		else {
			pq.push(c[i].e);
			ans = max(ans, (int)pq.size());
		}

	}

	cout << ans;

}
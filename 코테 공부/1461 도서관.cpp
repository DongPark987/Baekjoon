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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, Max = 0, ans = 0;
	cin >> N >> M;

	priority_queue<int> ppq;
	priority_queue<int, vector<int>, greater<int>> npq;


	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		Max = max(abs(tmp), Max);
		if (tmp < 0) {
			//Max = -(max(abs(Max), abs(tmp)));
			npq.push(tmp);
		}
		else {
			//Max = (max(abs(Max), abs(tmp)));
			ppq.push(tmp);
		}
	}

	while (!npq.empty()) {
		int top = abs(npq.top());
		//cout << "[" << npq.top() << "]: ";
		for (int i = 0; i < M && !npq.empty(); i++) {
			//cout << npq.top() << ", ";
			npq.pop();
		}
		//cout << endl;
		ans += top * 2;
	}
	while (!ppq.empty()) {
		int top = ppq.top();
		//cout << "[" << ppq.top() << "]: ";
		for (int i = 0; i < M && !ppq.empty(); i++) {
			//cout << ppq.top() << ", ";
			ppq.pop();
		}
		//cout << endl;
		ans += top * 2;
	}
	cout << ans - Max;
}
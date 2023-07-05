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

	int T = 0;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long ans = 0;
		int N = 0; 
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			pq.push(tmp);
		}
		while (true) {
			if (pq.size() == 1)break;
			long long f1 = pq.top();
			pq.pop();
			long long f2 = pq.top();
			pq.pop();
			ans += f1 + f2;
			pq.push(f1 + f2);
		}	
		cout << ans << endl;;
	}

}
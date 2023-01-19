//#include <stdio.h>
#include <iostream>
//#include <stack>
//#include <queue>
#include <vector>
//#include <deque>
//#include <string.h>
//#include <string>
#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, Max = 0, Min = 0, Mid = 0, ans = 0;
	long long M;
	vector<int> v;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		Max = max(tmp, Max);
	}
	sort(v.begin(), v.end(), greater<>());
	while (Max >= Min)
	{
		Mid = (Max + Min) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (v[i] < Mid) break;
			sum += v[i] - Mid;
		}

		if (sum >= M) {
			ans = Mid;
			Min = Mid + 1;
		}else {
			Max = Mid - 1;
		}
	}

	cout << ans;
}
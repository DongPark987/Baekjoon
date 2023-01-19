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

struct MyStruct {
	int time = 0, enter_count = 0;
	int pre_time = 0;
	vector<int> link;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	MyStruct ms[501];
	queue<int> work_list;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ms[i].time;
		int tmp = 0;
		while (true) {
			cin >> tmp;
			if (tmp == -1) break;
			ms[tmp-1].link.push_back(i);
			ms[i].enter_count++;
		}
		if (ms[i].enter_count == 0) {
			work_list.push(i);
			ms[i].pre_time = 0;
		}
	}

	while (!work_list.empty()) {
		int size = work_list.size();
		for (int i = 0; i < size; i++) {
			int cur = work_list.front();
			work_list.pop();
			for (int i : ms[cur].link) {
				ms[i].enter_count--;
				ms[i].pre_time = max(ms[cur].pre_time + ms[cur].time, ms[i].pre_time);
				if (ms[i].enter_count == 0) {
					work_list.push(i);
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << ms[i].time + ms[i].pre_time << "\n";
}

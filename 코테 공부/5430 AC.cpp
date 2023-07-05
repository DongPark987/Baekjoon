#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <sstream>

using namespace std;
#pragma warning(disable : 4996)

int T, n;
string fn;
string num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> fn;
		cin >> n;
		char a;
		cin >> a;
		cin >> num;
		num.pop_back();

		int L = 0, R = num.length() - 1;
		bool isReverse = false;
		bool success = true;

		for (char c : fn) {
			//cout << "()" << c << endl;
			if (c == 'R') {
				if (isReverse)
					isReverse = false;
				else
					isReverse = true;
			}
			else {
				if (n == 0) {
					success = false;
					break;
				}
				if (n == 1) {
					n--;
					continue;
				}
				if (isReverse == false) {
					while (num[L] != ',')L++;
					L++;
					n--;
				}
				else {
					while (num[R] != ',')R--;
					R--;
					n--;
				}
			}

		}
		if (success == true) {
			if (n == 0) {
				cout << "[]\n";
			}
			else {
				if (isReverse == false) {
					cout << '[';
					for (int i = L; i <= R; i++)
						cout << num[i];
					cout << "]\n";
				}
				else {
					cout << '[';
					string buff;
					for (int i = R; i >= L; i--) {
						if (num[i] == ',') {
							reverse(buff.begin(), buff.end());
							cout << buff << ',';
							buff.clear();
						}
						else {
							buff.push_back(num[i]);
						}
					}
					reverse(buff.begin(), buff.end());
					cout << buff;
					buff.clear();
					cout << "]\n";
				}
			}
		}
		else {
			cout << "error\n";
		}
				
	}
}
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
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		string rstr;
		cin >> str;
		rstr = str;
		reverse(rstr.begin(), rstr.end());
		if (str == rstr) {
			cout << 0 << "\n";
			continue;
		}

		bool check = true;
		bool life = true;
		int L = 0, R = str.length() - 1;
		//cout << L << " " << R;
		while (L < R) {
			//cout << str[L] << str[R] << endl;
			if (str[L] == str[R]) {
				L++; R--;
			}
			else {
				if (life == true) {
					life = false;
					if (str[L + 1] == str[R]) {
						L++;
					}
					else {
						check = false;
						break;
					}
				}
				else {
					check = false;
					break;
				}
			}
		}

		bool check2 = true;
		life = true;
		L = 0; R = str.length() - 1;
		//cout << L << " " << R;
		while (L < R) {
			//cout << str[L] << str[R] << endl;
			if (str[L] == str[R]) {
				L++; R--;
			}
			else {
				if (life == true) {
					life = false;
					if (str[L] == str[R - 1]) {
						R--;
					}
					else {
						check2 = false;
						break;
					}
				}
				else {
					check2 = false;
					break;
				}
			}
		}


		if (check || check2) {
			cout << 1 << '\n';
		}
		else {
			cout << 2 << '\n';
		}
	}
}
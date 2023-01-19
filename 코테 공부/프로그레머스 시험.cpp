#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

char dsign[3] = { '-','+','*' };
long long comb[6][3]{ {0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0} };

long long calc(long long n1, long long n2, char s) {
    if (s == '-')
        return n1 - n2;
    if (s == '+')
        return n1 + n2;
    if (s == '*')
        return n1 * n2;
}


long long solution(string expression) {
    vector<long long> num;
    vector<char> sign;

    string t_num;
    for (long long i = 0; i < expression.size(); i++) {
        if (isdigit(expression[i])) {
            t_num += expression[i];
        }
        else {
            num.push_back(stoi(t_num));
            sign.push_back(expression[i]);
            t_num.clear();
        }
        if (i == expression.size() - 1)
            num.push_back(stoi(t_num));
    }

    long long Max = 0;

    for (long long i = 0; i < 6; i++) {
        vector<long long> t_num = num;
        vector<char> t_sign = sign;
        long long n_cur = 0, s_cur = 0;
        //cout << "==============================" << endl;
        for (long long j = 0; j < 3; j++) {
            bool left = false;
            char cur_sign = dsign[comb[i][j]];
            //cout << cur_sign << endl;
            for (long long n_cur = 0, s_cur = 0; s_cur < t_sign.size();) {
                if (t_sign[s_cur] == cur_sign) {
                    //cout << t_num[n_cur] << cur_sign << t_num[n_cur + 1] << endl;
                    t_num[n_cur] = calc(t_num[n_cur], t_num[n_cur + 1], cur_sign);
                    t_num.erase(t_num.begin() + n_cur+1);
                    t_sign.erase(t_sign.begin() + s_cur);
                    
                }
                else {
                    s_cur++;
                    n_cur++;
                }
            }
            cout << "1¹ø: ";
            for (long long i : t_num)
                cout << i << " ";
            cout << endl;
            
            //cout << endl;
        }
        Max = max(Max, abs(t_num[0]));
    }

    //cout << Max;



    return 0;
}

int main() {

    solution("100-200*300-500+20");
    
}
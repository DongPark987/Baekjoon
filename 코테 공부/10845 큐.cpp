#include <stdio.h>
//#include <stack>
#include <string.h>
#include <queue>
//#include <vector>
//#include <iostream>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)


int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);*/

    int N;
    char str[10];
    queue<int> q;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        if (strcmp(str,"push")==0) {
            int tmp;
            scanf("%d\n", &tmp);
            q.push(tmp);
        }
        else if (strcmp(str, "pop") == 0) {
            if (q.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", q.front());
                q.pop();
            }
        
        }
        else if (strcmp(str, "size")==0) {
            printf("%d\n", q.size());
        }
        else if (strcmp(str, "empty") == 0) {
            if (q.empty()) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else if (strcmp(str, "front") == 0) {
            if (q.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", q.front());
            }

        }
        else if (strcmp(str, "back") == 0) {
            if (q.empty()) {
                printf("-1\n");
            }
            else {
                printf("%d\n", q.back());
            }
        }
        
    }


}
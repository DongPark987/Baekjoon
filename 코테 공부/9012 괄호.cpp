//#include <stdio.h>
//#include <stack>
////#include <string.h>
////#include <queue>
////#include <vector>
////#include <iostream>
////#include <algorithm>
//
//using namespace std;
//#pragma warning(disable : 4996)
//
//
//
//int main() {
//    /*ios_base::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);*/
//
//    int N;
//    char str[51];
//    scanf("%d", &N);
//
//    for (int i = 0; i < N; i++) {
//        int cur = 0, cnt = 0;
//        scanf("%s", str);
//        while (str[cur] != '\0') {
//            if (str[cur] == '(') {
//                cnt++;
//            }
//            else {
//                if (cnt == 0) {
//                    cnt = 1000;
//                    break;
//                }
//                else {
//                    cnt--;
//                }
//            }
//            cur++;
//        }
//;
//        if (cnt == 0) {
//            printf("YES\n");
//        }
//        else {
//            printf("NO\n");
//        }
//    }
//}
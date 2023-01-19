//#include <stdio.h>
//#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

struct MyNode {
    int lCnt = 0, rCnt = 0;
    int left = -1, right = -1;
    int loc = 0;
};

int N;
int findRoot[10001] = { 0, };
int Min[10001] = { 0, };
int Max[10001] = { 0, };
MyNode Node[10001];

int dfsChildCnt(int cur,int level) {
    int sum = 0;
    if (Node[cur].left != -1) {
        Node[cur].lCnt = dfsChildCnt(Node[cur].left, level++) + 1;
    }
    if (Node[cur].right != -1) {
        Node[cur].rCnt = dfsChildCnt(Node[cur].right, level++) + 1;
    }
    return Node[cur].lCnt + Node[cur].rCnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        findRoot[t1]++;
        findRoot[t2]++;
        findRoot[t3]++;
        Node[t1].left = t2;
        Node[t1].right = t3;                                                                                                                                                                                                                                                     
    }

    int root;
    for (int i = 1; i <= N; i++) {
        if (findRoot[i] == 1) {
            root = i;
            break;
        }
    }

    dfsChildCnt(root, 1);

    queue<int> q;
    int lAns = 1, wAns = 1;
    int level = 2;

    q.push(root);
    while (!q.empty()) {
        int size = q.size();

        if (size != 1) {
            int L = 0;
            int R = 0;
            for (int i = 0; i < size; i++) {
                MyNode& t = Node[q.front()];
                q.pop();
                if (t.left != -1) {
                    q.push(t.left);
                    Node[t.left].loc = t.loc - Node[t.left].rCnt - 1;
                    if (L == 0)
                        L = Node[t.left].loc;
                    R = Node[t.left].loc;
                }
                if (t.right != -1) {
                    q.push(t.right);
                    Node[t.right].loc = t.loc + Node[t.right].lCnt + 1;
                    if (L == 0)
                        L = Node[t.right].loc;
                    R = Node[t.right].loc;
                }
               
            }

            if (wAns < R - L + 1) {
                lAns = level;
                wAns = R - L + 1;
            }
        }
        else {
            MyNode& t = Node[q.front()];
            q.pop();
            int L = 0;
            int R = 0;
            if (t.left != -1) {
                q.push(t.left);
                Node[t.left].loc = t.loc - Node[t.left].rCnt - 1;
            }
            if (t.right != -1) {
                q.push(t.right);
                Node[t.right].loc = t.loc + Node[t.right].lCnt + 1;
            }
        }
        level++;
    }


    cout << lAns << " " << wAns;

}
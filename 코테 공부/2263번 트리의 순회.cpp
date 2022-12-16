/*
//#include <stdio.h>
//#include <string.h>
//#include <queue>
#include <iostream>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

int in[100001] = { 0, }; //인오더 값
int post[100001] = { 0, }; //포스트오더 값
int index[1000001] = { 0, }; //인오더의 루트 위치 인덱스
int n = 0;
//1 ~ n 까지 중복번호가 없다는 가정이 있기에 인덱스 생성 가능

void printPreOrder(int is, int ie, int ps, int pe) {
	//각각의 배열의 시작점이 끝점보다 커지면 방문 종료
	if (is > ie || ps > pe)
		return;

	//분할된 상태에서 루트는 항상 포스트 오더의 마지막 요소
	int root = post[pe];

	//방문하는 규칙에 의해 각각 호출된 함수에서 root 출력은
	//preorder의 출력과 순서가 같다.
	cout << root << ' ';

	//좌측에 서브트리의 크기
	int left = index[root] - is;

	//우측에 서브트리의 크기
	int right = ie - index[root];

	//재귀호출을 이용한 좌측 노드 방문
	printPreOrder(is, index[root] - 1, ps, ps + left - 1);
	//재귀호출을 이용한 우측 노드 방문
	printPreOrder(index[root] + 1, ie, pe - right, pe - 1);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		index[in[i]] = i; //수행시간 단축을 위한 inorder의 인덱스 생성
	}
	for (int i = 0; i < n; i++)
		cin >> post[i];

	printPreOrder(0, n - 1, 0, n - 1);
}
*/
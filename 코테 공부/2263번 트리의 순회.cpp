/*
//#include <stdio.h>
//#include <string.h>
//#include <queue>
#include <iostream>
//#include <algorithm>

using namespace std;
#pragma warning(disable : 4996)

int in[100001] = { 0, }; //�ο��� ��
int post[100001] = { 0, }; //����Ʈ���� ��
int index[1000001] = { 0, }; //�ο����� ��Ʈ ��ġ �ε���
int n = 0;
//1 ~ n ���� �ߺ���ȣ�� ���ٴ� ������ �ֱ⿡ �ε��� ���� ����

void printPreOrder(int is, int ie, int ps, int pe) {
	//������ �迭�� �������� �������� Ŀ���� �湮 ����
	if (is > ie || ps > pe)
		return;

	//���ҵ� ���¿��� ��Ʈ�� �׻� ����Ʈ ������ ������ ���
	int root = post[pe];

	//�湮�ϴ� ��Ģ�� ���� ���� ȣ��� �Լ����� root �����
	//preorder�� ��°� ������ ����.
	cout << root << ' ';

	//������ ����Ʈ���� ũ��
	int left = index[root] - is;

	//������ ����Ʈ���� ũ��
	int right = ie - index[root];

	//���ȣ���� �̿��� ���� ��� �湮
	printPreOrder(is, index[root] - 1, ps, ps + left - 1);
	//���ȣ���� �̿��� ���� ��� �湮
	printPreOrder(index[root] + 1, ie, pe - right, pe - 1);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		index[in[i]] = i; //����ð� ������ ���� inorder�� �ε��� ����
	}
	for (int i = 0; i < n; i++)
		cin >> post[i];

	printPreOrder(0, n - 1, 0, n - 1);
}
*/
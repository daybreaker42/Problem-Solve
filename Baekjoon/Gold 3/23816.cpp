// Baekjoon No. 23816 �ʰ��̰��̰��� - 2209~220928 solved
// Time Complexity O(logn)
// #math #dp

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int hanger(int h, int n, int m, int cNum);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cNum = 0;
	int i;
	cin >> n >> m;

	cNum = hanger(1, n, m, cNum);
	cout << cNum;
	return 0;
}

int hanger(int h, int n, int m, int cNum) {
	int i = n;
	while (i > 0 && ((m - (int)pow(2, h - 1) * i) < 0 || (m - (int)pow(2, h - 1) * i) % (int)pow(2, h))) {
		i--;
	}
	m -= (int)pow(2, h - 1) * i;

	// ���� ������ �߰��� �ٴ� �ʰ��� ���� / 2��ŭ ���� �ʰ��̿��� ����� ��.
	if(h > 1)
		cNum -= pow(2, h - 2) * i;
	// �ʰ��� �߰�
	if(h < 4)
		cNum += pow(2, h - 1) * i;
	// ���� ������ �����ϴ��� ����
	if (m == 0)
		return cNum;
	else {
		if (i == 0 || h == 4)
			return -1;
		else
			return hanger(h + 1, i, m, cNum);
	}
		
}
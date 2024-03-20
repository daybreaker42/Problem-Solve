// BOJ 24453 - �����, 230102 solved
// ������ �ٲ㼭 �����غ���
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
	fastio;
	/** 
	* n - �ۼ��� �� �ڵ� �� ��
	* m - ������ �ִ� ���� ����
	* x - ��Ƽ�Ͱ� ������ �ذ��� �� �ִ� �ּ� ���� ���� �ڵ� �� ����
	* y - �α԰� �ذ��ϰ� ���� �ּ� ���� �� ����
	* ��� - �����Ͱ� �ذ��� �� �ִ� �ִ� ���� ����
	*/
	int n, m, x, y;
	int maxLineNum = 0;
	int minYNum;
	cin >> n >> m;
	vector<int> errorSum(n, 0);	// �� ĭ���������� error line ���� ����
	int idx = 1;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		errorSum[tmp - 1]++;
		for (; idx < tmp - 1; idx++) {
			errorSum[idx] += errorSum[idx - 1];
		}
	}
	for (; idx < n; idx++) {
		errorSum[idx] += errorSum[idx - 1];
	}

	cin >> x >> y;

	// solving
	minYNum = x;
	// 1��°��~x��°�ٱ��� error line ���� ��
	minYNum = min(errorSum[x - 1], minYNum);
	maxLineNum = m - minYNum;
	for (int i = 0; i < n - x; i++) {	// 2+i��°��~ 1+i+x��°�ٱ��� error line ���� ��
		if (minYNum <= y) break;
		// x���� ���� �� �ȿ� ��� �ִ� error line ���� �� �ּ� ���� ã��
		minYNum = min(errorSum[i + x] - errorSum[i], minYNum);
		maxLineNum = m - minYNum;
	}

	if (maxLineNum > m - y) {	// == minYNum < y
		cout << m - y;
	}
	else {
		cout << maxLineNum;
	}

	return 0;
}
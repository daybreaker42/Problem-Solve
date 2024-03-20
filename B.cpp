#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
/*
n���� �۾� -> 
i��° �۾���
- tiȸ �ٹ� ���� �ʿ�
- di���� ������ �� �۾��� ������ ��

- �����Ϻ��� ������Ʈ ������ -> i => 5, 6, 12, 13, ... 7*i + 5�� 7*i + 6���� �ָ�

- ���Ͽ� �ð��� -> A��, �ָ��� B��
- A���� B�� ������ �����ؼ� ��Ȯ�� M�� ������ ��
- A <= B
- 0 <= M <= 100

- ���ϱٹ� - �۾� �� ���� �� �� ���� ����
- �ð��ܱٹ� - ������ �۾� 1ȸ ������

- �ָ� �ð��� �ٹ� -> �ּ�ȭ�ؾ���



output
- ������ ��Ȯ�� M�� ������ ��� �۾��� ���� ���� ������ ���� �� �ִ� �ָ� �ð� �� �ٹ���
�ּ� Ƚ���� ����ؾ���.
- ������ ��Ȯ�� M�� ������ ��� �ٹ��� ���� ���� ������ ���� �� ������ -> -1 ���
*/

// �ش� �ϼ����� �� �� �ִ� �ִ� ���� ���� ��ȯ
int maxWorkCnt(int daysNum, bool includeWeekend) {
	int maxCnt = 0;
	int weekNum = daysNum / 7 + 1;
	
	maxCnt += (weekNum - 1) * 5 * 2;
	if (includeWeekend) {
		maxCnt += (weekNum - 1) * 2;	// �ָ� �� ����
	}
	// ������ �ְ� �ð��� ���� ī��Ʈ
	if (daysNum % 7 > 0) {
		maxCnt += min(5, daysNum % 7) * 2;	// ���� �ð��ܴ� �ִ� 5�ϱ��� ����
		if (includeWeekend) {
			maxCnt += max(0, daysNum % 7 - 5);	// �ָ� ������ ����
		}
	}
	return maxCnt;
}

int main() {
	fastio;
	int n, a, b, m;
	cin >> n >> a >> b >> m;
	vector<int> endDate(n), workCnt(n);
	for (int i = 0; i < n; i++) {
		cin >> endDate[i] >> workCnt[i];
	}
	// solving
	int ans = 0;
	// case 2. n != 1; a, b, m = 0;

	if (workCnt[0] > maxWorkCnt(endDate[0], true)) {
		// �ָ� �ð��ܱ��� �ص� �� ������ ���
		cout << -1;
	}
	else if(workCnt[0] > maxWorkCnt(endDate[0], false)) {
		// �ָ� �ð��ܱ��� �ؾ� �۾��� ������ ���
		cout << workCnt[0] - maxWorkCnt(endDate[0], false);
	}
	else {
		// �ָ� �ð��� ���ص� �Ǵ� ���
		cout << 0;
	}



	return 0;
}
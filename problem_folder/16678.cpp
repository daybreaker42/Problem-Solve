#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100000

using namespace std;

int main() {
	fastio;
	int n;
	cin >> n;
	vector<int> honor(n);
	for (int i = 0; i < n; i++) {
		cin >> honor[i];
	}

	// solving
	int standard = 1;
	long long ans = 0;
	// 1. ������ ������
	sort(honor.begin(), honor.end());
	// 2. ���鼭 i��° ������ i + 1�� ���� ���� ����, ���ٸ� �ѱ�.
	for (int i = 0; i < n; i++) {
		// standard + 1 -> ���� �Ǿ�� �ϴ� ����
		if (honor[i] == standard - 1) continue;
		ans += honor[i] - standard;
		standard++;
	}

	cout << ans;
	return 0;
}

/*
�־��� ������ 1~n������ ������ ����� ���� �ʿ��� �ּ� ���̸� ���ϴ� ����.
�˰��� ���� ����
1. ���� ����
2. i��° ������ standard(�Ǿ�� �ϴ� ����)�� �� ��ŭ�� ans�� ����
3. standard�� 1 ������Ŵ
- ��, 2. ���� ���� ���ڰ� �ߺ��̸� �Ѿ(�ߺ��� ���� ��� ���ؾ� �Ѵ�.)
- ans�� �ִ��� int���� (�� 2*10^8)�� �Ѿ���� long long���� �����ؾ� �Ѵ�.
*/
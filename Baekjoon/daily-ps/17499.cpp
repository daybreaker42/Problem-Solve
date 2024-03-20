// BOJ 17499 - ������ ����Ʈ ����, 230131 solved
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int leftOver(int, int);

int main() {
	fastio;
	int N, Q;
	cin >> N >> Q;
	vector<ll> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// solving
	int s = 0;	// �� �������� �ϴ� shift ĭ ��

	for (; Q > 0; Q--) {
		// �� query���� ����
		int query;
		cin >> query;
		if (query == 1) {
			int idx, x;
			cin >> idx >> x;
			idx--;
			arr[leftOver(idx - s, N)] += x;
		}
		else {
			int tmp;
			cin >> tmp;
			if (query == 2) s += tmp;
			else s -= tmp;
		}
		s %= N;	// �̰� �����༭ ��� Ʋ��
	}

	// shift only once
	vector<ll> tarr(N);
	for (int i = 0; i < N; i++) {
		tarr[leftOver(i + s, N)] = arr[i];
	}
	arr = tarr;

	// output
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

int leftOver(int n, int r) {
	if (r < 0) r = -r;
	return (n % r + r) % r;
}
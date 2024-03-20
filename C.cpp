#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

// constants
constexpr ll INF = 9000000000000000000;
constexpr int LEN = 50;
constexpr int MAX = 1000000;
using namespace std;

/*
* - start, end�� ������ ���¿��� start~end���� ���µ� sum(����^2) �ּҰ� ���ϴ� ����
* -> �ִܰŸ� ���ϴ� ������ ��� => ���^2 �� �ּ�ȭ ����
* 
* 1. �� ������ �Ƿε� ����(�ٸ� ĭ ���� ^2)�� ���� ���� -> O(F * F / 2 *N*M) <= 3,125,000
*	- �� �������� �� �������� ���� ������������ ���� ����?  => �������� O(nlogn) 
*	-> O(F * NlogN) = O(F * FlogF)
* //2. ���ͽ�Ʈ�� �˰��� ����ؼ� start���� end������ �ּҰŸ�(�Ƿε�^2 �ּ�)����
*	// - �� ������ �ÿ��� ���� ���� -> O(L * T * F * N * M)
*	2.1. ���ͽ�Ʈ�� ����ϸ� O(F*logF)���� ����
*   => �� O(F*F*logF) <= 2500*lg50 ~= 14109
*	2.2. �÷��̵� �ͼ� ��� -> O(F*F*F)���� ����
*	=> �� O(F^4) <= 6.25*10^6
* 
* 2. ���ͽ�Ʈ�� �ȵ� -> �ᱹ T���� ��θ� ���� i���� j���� ���� �ִܰŸ��� ���ϴ� �˰����� �ʿ���.
* 
* - �Ƿε� �ִ��� = 6250000,
* - �Ϸ翡 ���� �� �ִ� �Ƿε� �ִ��� -> 6250000,
* - l <= 1000000 => �Ƿε� �� <= 6250000 * 1000000 = 6.25*10^12 = �� 60�� < 9*10^18
* => long long ����
* 
* - ���� T <= 10^6������, T�� 50^2�����ۿ� �ǹ̰� ����.
* - �� �̻� �Ѿ�� �ᱹ C[i]��  C[j]�� ������ �ִ� 50�� => F<=50�̹Ƿ�
* 
* - L�� ��������. 
*/

// globals
int formNum, l, t, n, m;
bool formation[LEN][LEN][LEN] = { 0 };	// ���� ���� ����

int firstFormIdx[MAX] = { 0 };
int lastFormIdx[MAX] = { 0 };	// ��¥�� ������ formation idx
int tiredValArr[LEN][LEN];
// �� idx���� �켱����ť �̿��� {�Ÿ�, idx} ����, ������ �� ���� -> minheap
priority_queue<pair<int, int>> minTiredValArr[LEN];

// functions
int getTiredVal(int, int);
void getOptimalTiredValSum(int, int, int, ll*, ll currentTiredVal);

int main() {
	fastio;
	// init
	cin >> formNum >> l >> t >> n >> m;
	// inputs formation
	for (int fIdx = 0; fIdx < formNum; fIdx++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> formation[fIdx][i][j];
			}
		}
	}
	// inputs other variables
	for (int i = 0; i < l; i++) {
		cin >> lastFormIdx[i];	// i + 1��° ���� ���������� �ÿ��� formation�� number ����
		lastFormIdx[i]--;		// ��ȣ�� �ֹǷ� 1�� ����
	}

	// firstFormIdx �ʱ�ȭ
	firstFormIdx[0] = 0;
	for (int i = 1; i < l; i++) {
		firstFormIdx[i] = lastFormIdx[i - 1];
	}
	// case 1. T == 1�϶�
	long long ans = 0;

	// 1. �Ƿε� �迭 �ʱ�ȭ - O(F^2 / 2 * N*M * lgF) <= 4*10^7
	for (int i = 0; i < formNum; i++) {
		for (int j = 0; j < i; j++) {	// ���� �Ʒ� �ﰢ�� �κи� ����
			if (i != j) {
				int tiredVal = getTiredVal(i, j);	// O(N*M)
				tiredValArr[i][j] = tiredVal;
				tiredValArr[j][i] = tiredVal;
				minTiredValArr[i].push({ -tiredVal, j });	// O(lgF)
				minTiredValArr[j].push({ -tiredVal, i });
			}
		}
	}

	cout << "TiredValArr making Finished\n";
	for (int i = 0; i < formNum; i++) {
		for (int j = 0; j < formNum; j++) {
			cout << tiredValArr[i][j] << " ";
		}
		cout << "\n";
	}

	// 2. �� ��¥�� �Ƿε� �ּڰ� ����
	
	for (int i = 0; i < l; i++) {
		cout << "current Date - " << i << "\n";
		int lfIdx = lastFormIdx[i], ffIdx = firstFormIdx[i];
		ll minTiredValSum = INF;
		vector<int> arr(t, 0);
		for (int p = 0; p < t; p++) {

		}

		ans += minTiredValSum;
	}

	cout << ans;
	return 0;
}

// �� formation�� �Ƿε� �����ִ� �Լ�, O(n * m)
int getTiredVal(int form1, int form2) {
	int diff = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (formation[form1][i][j] != formation[form2][i][j]) {
				diff++;
			}
		}
	}
	return diff * diff;
}

// start ���� end ���� tLeft ���� ��带 ���� ���� �� �ִ� �ּ� tiredVal�� ����
void getOptimalTiredValSum(int st, int ed, int tLeft, ll* minTiredValSum, ll currentTiredVal) {
	cout << "solving - " << tLeft << " th st - " << st << " ed - " << ed << "\n";
	if (tLeft == 1) {
		*minTiredValSum = min(*minTiredValSum, currentTiredVal + tiredValArr[st][ed]);
		return;
	}
	for (int midIdx = 0; midIdx < formNum; midIdx++) {	
		int cost = -minTiredValArr[st].top().first;
		// ��������� ���� ���� ���亸�� ũ�� ���� �ܰ�� ������ ����
		if (currentTiredVal + cost <= *minTiredValSum) {
			getOptimalTiredValSum(midIdx, ed, tLeft - 1, minTiredValSum, currentTiredVal + cost);
		}
		else {
			cout << "not opimal\n";
		}
	}

	return;
}
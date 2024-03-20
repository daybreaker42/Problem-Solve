// Baekjoon No. 1931 ȸ�ǽ� ���� - 221110 solved
// Time Complexity O(nlogn)
/* #Greedy
*
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

bool cmp(pair<int, int> o1, pair<int, int> o2);
int main() {
	fastIO;
	int n, cnt = 0, currentIdx;
	long long st, ed;
	int i;
	cin >> n;
	vector<pair<long long, long long>> times;
	for (i = 0; i < n; i++) {
		cin >> st >> ed;
		times.push_back(pair<long long, long long>{st, ed});
	}
	
	// solving
	sort(times.begin(), times.end(), cmp);
	cnt = 1;
	currentIdx = 0;
	for (i = 1; i < n; i++) {
		if (times[i].first >= times[currentIdx].second) {
			cnt++;
			currentIdx = i;
		}
	}
	cout << cnt;

	return 0;
}
bool cmp(pair<int, int> o1, pair<int, int> o2) {
	// �����Ҷ� .second�� ���� �� .first �κб��� ������ ������ ���߾���.
	if (o1.second == o2.second) return o1.first < o2.first;
	return o1.second < o2.second;
}
// Baekjoon No. 1822 - ������, 221103
// Time Complexity O(nlogn)
/*
* ���� A���� ��������, B���� ������ �ʴ� ����(A-B)���� ����ϴ� ����
* �� �ڷ��� ��� ���� �� ���� Ž���� �̿��� ������ �ذ��Ͽ���.
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
using namespace std;

bool contains(int num, vector<int>& arr, int st, int ed);
int main() {
	fastIO
	int aNum, bNum, tmp;
	int i;
	cin >> aNum >> bNum;
	vector<int> ans;
	// map<int, int> A;
	// map<int, int> B;
	vector<int> A(aNum);
	vector<int> B(bNum);
	for (i = 0; i < aNum; i++) {
		cin >> A[i];
	}
	for (i = 0; i < bNum; i++) {
		cin >> B[i];
	}

	// solving
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (i = 0; i < aNum; i++) {
		if (!contains(A[i], B, 0, bNum - 1)) {
			ans.push_back(A[i]);
		}
	}
	cout << ans.size() << "\n";
	// for (i = 0; i < ans.size(); i++)
	for(int num : ans)
		cout << num << " ";
	return 0;
}
bool contains(int num, vector<int>& arr, int st, int ed) {
	if (num == arr[st]) return true;
	else if (st >= ed) return false;
	int mid = (st + ed) / 2;
	if (num <= arr[mid]) return contains(num, arr, st, mid);
	else return contains(num, arr, mid + 1, ed);
}
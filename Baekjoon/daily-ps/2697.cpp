// BOJ - 2697 ������ ���ϱ�, 230102 solved
/** @explaination - 
* 
* ������ ������ Ž���ϸ� ���������� ����� �κ��� üũ�� ��, (����´� �� - n)
* ����� �κ��� �����ʿ� �ִ� �κм������� n���� ū �ּ� ��ҿ� ��ġ�� �ٲ� ��
* ������ �κм����� �� n�� ������ ��ġ�� ��� �ְ�
* ������ �κм����� �������ָ� �ȴ�.
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int search(string str, int st, int ed, char n);
void swap(char* c1, char* c2);
void insertionSort(string* str, int st, int ed);

int main() {
	fastio;
	int t;
	string A;
	
	cin >> t;
	for (; t > 0; t--) {
		bool isBiggest = true;
		cin >> A;
		
		int len = A.size();
		for (int i = len - 1; i > 0; i--) {
			// �� �ڸ��� �� �ڸ����� ���� �� -> �� Ŀ�� �� ����
			if (A[i - 1] < A[i]) {
				isBiggest = false;
				int targetIdx = search(A, i, len - 1, A[i - 1]);	// idx ���
				swap(&A[i - 1], &A[targetIdx]);	// A[i-1]���� ū �ּ� ��� [i, len)���� ã�� swap
				insertionSort(&A, targetIdx, len - 1);	// �ϴ� �������� ����, idx���
				reverse(A.begin() + i, A.end());
				break;
			}
		}
		if (isBiggest) {
			cout << "BIGGEST\n";
		}
		else {
			cout << A << "\n";
		}
	}
	
	return 0;
}

 
// @info - ���� �� n���� ū �ּ� ��� �ε����� ��ȯ�ϴ� �Լ�
int search(string str, int st, int ed, char n) {
	int idx = st;
	for (int i = st; i <= ed; i++) {
		if (str[i] <= n) break;
		idx = i;
	}
	return idx;
}

void swap(char* c1, char* c2) {
	char tmp = *c2;
	*c2 = *c1;
	*c1 = tmp;
	return;
}

void insertionSort(string* str, int st, int ed) {
	if (st == ed) return;
	for (int i = st; i < ed; i++) {
		if ((*str)[i] < (*str)[i + 1]) {
			swap(&(*str)[i], &(*str)[i + 1]);
		}
	}
	return;
}
// Baekjoon No. 1019 - å ������ 220121~220911
// Time Complexity O(logn)
// #Math
/** 
�� �ڸ����� �� ���ڵ��� �� ���� ����� ���� ������ �� �ִ��� ���̽��� ������ ���� ���� ���� ���ϴ� �˰���
������ 1~n���� ��� ���ڸ� str�� ��ȯ�� ���� �ϳ��� ���� �˰����� �ʹ� ��ȿ������.
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, length;
	int i, j;
	unsigned long long int cnt[10] = { 0 };
	cin >> n;

	// solving
	string number = to_string(n);
	length = number.length();
	// �����ڸ�~ �� �����ڸ� - 1 ����
	for (i = 0; i < length - 1; i++) {
		// 0�� ���� ���. 0���� �� �ڸ����� ���� ���� �����Ƿ� �� ���� �����ϰ� 0�϶��� 0�� �ƴ� �� (Ŭ ��)�� ���.
		if(number[length - 1 - i] - '0' != 0)
			cnt[0] += (n / (int)pow(10, i + 1)) * (int)pow(10, i);
		else
			cnt[0] += (n / (int)pow(10, i + 1) - 1) * (int)pow(10, i) + n % (int)pow(10, i) + 1;

		for (j = 1; j < 10; j++) {
			// �� �ڸ��� ���� (number[length - 1 - i]) �� j (���� ������ ���ϴ� ��)���� Ŭ ��, ���� ��, ���� �� �������� ������ �з�.
			if (number[length - 1 - i] - '0' > j)
				cnt[j] += (n / (int)pow(10, i + 1) + 1) * (int)pow(10, i);
			else if (number[length - 1 - i] - '0' == j)
				cnt[j] += n / (int)pow(10, i + 1) * (int)pow(10, i) + n % (int)pow(10, i) + 1;
			else
				cnt[j] += (n / (int)pow(10, i + 1)) * (int)pow(10, i);
		}
	}

	i = length - 1;
	// �� �����ڸ�
	for (j = 1; j < 10; j++) {
		if (number[0] - '0' > j)
			cnt[j] += (int)pow(10, i);
		if (number[0] - '0' == j) {
			cnt[j] += n % (int)pow(10, i) + 1;
		}
	}
	
	for (i = 0; i < 10; i++)
		cout << cnt[i] << " ";

	return 0;
}
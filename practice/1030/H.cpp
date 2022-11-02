// Baekjoon No. 17413
// Time Complexity 
// #

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main() {
	fastIO
	string str, tmp, flipped;
	int i, strLen, mode, st;
	// cin >> str;
	getline(cin, str);
	strLen = str.length();
	mode = 1;	// 1�� ������, 0�� �±�(�ȵ�����)
	tmp = "";
	flipped = "";
	st = 0;	// �ٲ� ���� ���� ��ġ
	for (i = 0; i < strLen; i++) {
		if (mode) {	// �ܾ� ���϶�
			if (str[i] == '<') {
				if (st != i) {
					str.replace(st, i - st, tmp);
					tmp = "";
				}
				mode = 0;
				st = i;
			}
			else {
				if (str[i] == ' ' || i == strLen - 1) {
					if (i == strLen - 1) {
						tmp = str[i] + tmp;
						i++;
					}
					str.replace(st, i - st, tmp);
					tmp = "";
					st = i + 1;
				}
				else
					tmp = str[i] + tmp;
			}
		}
		else {	// �±� ���϶�
			if (str[i] == '>') {
				mode = 1;
				st = i + 1;
			}
		}
	}

	cout << str;
}
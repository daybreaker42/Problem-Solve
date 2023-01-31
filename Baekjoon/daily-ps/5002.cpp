#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int diff = 0, maxNum = 0;
char cache[2];
stack<int> s;
map<char, int> m = { {'W', -1}, {'M', 1} };

void popFirst();
void popSecond();
void handlePeople();

int main() {
	fastio;
	int n, len;
	string people;
	cin >> n >> people;
	len = people.length();

	// solving
	bool isFinished = false;
	// stack�� ����� ���� �ڿ������� �������
	for (int i = 0; i < len; i++) {
		s.push(people[len - i - 1]);
	}

	// cache�� 1, 2��° ��� ���� �������
	cache[0] = s.top();
	if (s.size() > 1) {
		s.pop();
		cache[1] = s.top();
	}
	else {
		cache[1] = 0;
	}
	
	// stack�� �ִ� ���� �ϳ��� ���鼭 �ݺ�
	while (s.size() > 1 && abs(diff) <= n) {
		if (diff == 0) {
			// ���� == 0�λ��� -> 2��°��� �鿩����
			popSecond();
			maxNum++;
			diff += m[cache[1]];
		}
		else {
			if (abs(diff + m[cache[0]]) < abs(diff)) {
				// ù ��° ����� �鿩�������� ���̰� �پ�� ��
				popFirst();
				maxNum++;
				diff--;
			}
			else if (abs(diff + m[cache[1]]) < abs(diff)) {
				// �� ��° ����� �鿩�������� ���̰� �پ�� ��
				popSecond();
				maxNum++;
				diff--;
			}
			else {
				// ù��°�� �ι�°�� ���پ�鶧
				if (diff >= n) {
					// ���� ������
					isFinished = true;
					diff += m[cache[0]];
					break;
				}
				else {
					popSecond();
					maxNum++;
					diff++;
				}
			}
		}
	}

	if(abs(diff) <= n) {
		// �ϴ� ���� �� ������ ����
		if (abs(diff + m[cache[0]]) < abs(diff)) {
			// ù ��° ����� �鿩�������� ���̰� �پ�� ��
			maxNum++;
			diff--;
			cache[0] = 0;
		}
		else if (abs(diff + m[cache[1]]) < abs(diff)) {
			// �� ��° ����� �鿩�������� ���̰� �پ�� ��
			maxNum++;
			diff--;
			cache[1] = 0;
		}


		if (cache[0] > 0 && abs(diff + m[cache[0]]) <= n) {
			// �ƴϸ� diff < n�̸� �߰�
			diff += cache[0];
			cache[0] = 0;
			maxNum++;
		}
		if (cache[1] > 0 && abs(diff + m[cache[1]]) <= n) {
			// �ƴϸ� diff < n�̸� �߰�
			diff += cache[1];
			cache[1] = 0;
			maxNum++;
		}
	}
	cout << maxNum;
}

void popFirst() {
	cache[0] = cache[1];
	popSecond();
}
void popSecond() {
	s.pop();
	cache[1] = s.top();
}
void handlePeople(int i, char gender) {
	if (cache[0] == gender) {
		diff += i;
		popSecond();
	}
	else if (cache[1] == gender) {
		diff += i;
		popSecond();
	}
	else {
		diff -= i;
		popFirst();
	}
}
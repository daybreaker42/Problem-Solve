#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define YMAX 100
#define XMAX 1000
using namespace std;

/*
* 1. ��ũ �¿� ��Ī
* 2. W, Y, B�� �ϳ��� ��ĥ�Ǿ����, Ư�� �׵θ��� B��(�̰� �⺻������ �̷��� ����)
* 3. ��ũ�� ������� 2��, ������� 1��, �Ķ����� 1���� �̷��������.
* 4. �� ��� ������ �߾� ���� �¿��Ī�̾�� ��
* 5. ��� ��� ������ ����� ����� �� ĭ �̻� ���� �����ؾ� ��
* 
* - �ּ�ũ�� 3 * 5 -> �׵θ� �����ϸ� 1 * 3
*/

// globals
int y, x;
string mark[YMAX];
bool isVisited[YMAX][XMAX] = { 0 };

// functions
int areaNum();
void checkCell(int, int);
void printMark();

int main() {
	fastio;
	// input
	cin >> y >> x;
	cin.ignore();	// remove buffer
	for (int i = 0; i < y; i++) {
		getline(cin, mark[i]);
	}
	// solving
	// 0. �׵θ� B�� �ʱ�ȭ(Ȥ�ø���)
	for (int i = 0; i < y; i++) {
		mark[i][0] = 'B';
		mark[i][x - 1] = 'B';
	}
	for (int j = 0; j < x; j++) {
		mark[0][j] = 'B';
		mark[y - 1][j] = 'B';
	}

	// 1. �־��� mark���� Blue�κ� ��Ī���� ���� - �׵θ��� �˻� x(������ ���� B����)
	for (int i = 1; i < y - 1; i++) {
		for (int j = 1; j < x / 2; j++) {
			// ��Ī�� �� ĭ �� �ϳ��� B�����̸� ������ �ϳ��� B�������� ������
			if (mark[i][j] != mark[i][x - 1 - j]) {
				mark[i][j] = 'B';
				mark[i][x - 1 - j] = 'B';
			}
		}
	}
	// printMark();	// debug
	// 2. ���� X�� �Ǿ��ִ� ������ '�ϳ�'�� �ִ��� �˻�
	int areas = areaNum();
	if (areas != 1) {
		// cout << "areas : " << areas << endl;
		cout << "NO";
		return 0;
	}
	// 3. ���� ���� �� x������ �� ���� �� ���� �� ���� W�� ��� ������ Y�� ����
	bool isPicked = false;
	for (int j = 1; j < x / 2; j++) {
		for (int i = 1; i < y - 1; i++) {
			int x_opp = x - 1 - j;	
			// �ݴ����̶��� �� ĭ �̻� �������־����
			if (x_opp - j > 1 && mark[i][j] == 'X') {
				mark[i][j] = 'W';
				mark[i][x_opp] = 'W';
				isPicked = true;
				break;
			}
		}
		if (isPicked) {
			break;
		}
	}
	// ���� ���� Y�� ä��
	for (int i = 1; i < y - 1; i++) {
		for (int j = 1; j < x - 1; j++) {
			if (mark[i][j] == 'X') {
				mark[i][j] = 'Y';
			}
		}
	}

	// 4. �˻��ؼ� �ȵǸ� NO ���
	// �� ���� 2���鼭 ��Ī����, Y������ �����ϴ����� �˻��ϸ� ��
	// Y������ �����Ҽ��ۿ� ���� -> X������ 1������ ����!
	/*
	* �� ������ ���� ���ߴٴ� �� 
	* - x�� Ȧ���� ��� ���ٸ� �����־��ų�
	* - x�� ¦���� x/2, x/2+1�� �� ������ ���� ���� �ϴ� ���
	*/ 
	if (!isPicked) {
		cout << "NO";
		return 0;
	}

	
	cout << "YES\n";
	// output
	printMark();
	
	return 0;
}

// X�� �Ǿ��ִ� ������ ���� ��ȯ, �׵θ��� �˻� x
int areaNum() {
	int areaCnt = 0;
	for (int i = 1; i < y - 1; i++) {
		for (int j = 1; j < x - 1; j++) {
			// �湮 x�ÿ���
			if (mark[i][j] == 'X' && !isVisited[i][j]) {
				checkCell(j, i);
				areaCnt++;
			}
		}
	}
	return areaCnt;
}

// ��������� ������ ���� ǥ��
void checkCell(int px, int py) {
	isVisited[py][px] = true;
	int xArr[] = { 1, -1, 0, 0 }, yArr[] = {0, 0, 1, -1};
	for (int i = 0; i < 4; i++) {
		int x_after = px + xArr[i], y_after = py + yArr[i];
		if (x_after >= 0 && x_after < x && y_after >= 0 && y_after < y 
			&& !isVisited[y_after][x_after] && mark[y_after][x_after] == mark[py][px]) {
			checkCell(x_after, y_after);
		}
	}
	return;
}

// mark�迭 ���
void printMark() {
	for (int i = 0; i < y; i++) {
		cout << mark[i] << "\n";
	}
	return;
}
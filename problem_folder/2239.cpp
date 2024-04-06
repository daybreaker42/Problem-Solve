/*
* ������ �Է¹޾� ���� ������ �˰���
* ��Ʈ��ŷ ���
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 9
#define BLK_SIZE 3

using namespace std;

short sudoku_arr[SIZE][SIZE] = { 0 };
short input_arr[SIZE][SIZE] = { 0 };

bool solve_sudoku(int r, int c);
vector<bool> available_values(int r, int c);

int main() {
	fastio;
	// inputs
	for (int i = 0; i < SIZE; i++) {
		string line;
		getline(cin, line);
		for (int j = 0; j < SIZE; j++) {
			input_arr[i][j] = line[j] - '0';
			sudoku_arr[i][j] = line[j] - '0';
		}
	}

	
	// solving
	bool result = solve_sudoku(0, 0);
	if (!result) {
		cout << "ERROR!\n";
	}

	// output
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << sudoku_arr[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}

// ��ͷ� ������ Ǫ�� �Լ�
bool solve_sudoku(int r, int c) {
	if (r == 9) return true;
	if (c == 9) {
		return solve_sudoku(r + 1, 0);
	}

	if (input_arr[r][c] == 0) {
		// ���� ������
		return solve_sudoku(r, c + 1);
	}
	else {
		// ���� ������ ������ �� �����ϱ�
		vector<bool> valueChecker = available_values(r, c);
		for (int idx = 0; idx < valueChecker.size(); idx++) {
			if (valueChecker[idx]) {
				sudoku_arr[r][c] = idx + 1;
				if (solve_sudoku(r, c + 1)) {
					return true;
				}
				sudoku_arr[r][c] = input_arr[r][c];
			}
		}
		// ������ �� ���� ���
		return false;
	}
}

// �ش� ĭ�� ������ �� �迭 ����
vector<bool> available_values(int r, int c) {
	// �ϴ� ���� true�� ����
	vector<bool> valueChecker = vector<bool>(9, true);
	// ������ �� ã��
	for (int i = 0; i < SIZE; i++) {
		// �ش� �� �˻�
		if (sudoku_arr[r][i]) {
			valueChecker[sudoku_arr[r][i] - 1] = false;
		}
		// �ش� �� �˻�
		if (sudoku_arr[i][c]) {
			valueChecker[sudoku_arr[i][c] - 1] = false;
		}
	}

	// �ش� ��� �˻�
	int blk_r = r / 3 * 3;
	int blk_c = c / 3 * 3;
	for (int i = 0; i < BLK_SIZE; i++) {
		for (int j = 0; j < BLK_SIZE; j++) {
			if (sudoku_arr[blk_r + i][blk_c + j] != 0) {
				valueChecker[sudoku_arr[blk_r + i][blk_c + j] - 1] = false;
			}
		}
	}

	return valueChecker;
}
// Baekjoon No. 1043 ������ - 221102~ 221108
// Time Complexity O(n^2)
/*
* ���� ��Ƽ�� �ִ� ����鳢�� �ϴ� ���� ��� ������� ���� ��, ��� ��Ƽ �Է��� �� �ް� ���� 
* �� ������ �� ��Ƽ�� �ִ� ������ �� ������ ������ ��� ����� �� 
* �� ���̶� ������ �˰� �ִ� ����� �ִ��� dfs�� üũ�ϴ� ����.
* 
* �˰��򺸴� ���� ������ �� ������ �������.
* 
* dfs ����� �� visited �ʱ�ȭ �� �������!
*/
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

// int knowing_status[SIZE + 1] = { 0 };	// �ε��� 1���� ����
// int party_people[SIZE][SIZE] = { 0 };

int dfs(int idx, int n, vector<vector<int>> &relations, vector<int> &visited, vector<int> &status);
int main() {
	fastIO;
	bool isLieable;
	int n, m, k, tmp, idx, cnt;
	int i, j, l;
	cin >> n >> m >> k;
	vector<int> status(n, 0);
	vector<vector<int>> parties(m);
	vector<vector<int>> relations(n, vector<int>(n, 0));
	for (i = 0; i < k; i++) {
		cin >> tmp;
		status[tmp - 1] = 1;
	}
	for (i = 0; i < m; i++) {
		cin >> tmp;
		// party init
		for (j = 0; j < tmp; j++) {
			cin >> idx;
			parties[i].push_back(idx - 1);
		}
		// inits relations
		for (j = 0; j < tmp; j++) {
			for (l = 0; l < tmp; l++) {
				if (j != l) {
					relations[parties[i][j]][parties[i][l]] = 1;
					relations[parties[i][l]][parties[i][j]] = 1;
				}
			}
		}
	}
	// solving
	cnt = 0;
	for (i = 0; i < m; i++) {
		// party�� �� �ο� for������ ���鼭, visited == 0�̶�� dfs������ �� ���̶� status == 1���� �Ǻ�
		isLieable = true;
		vector<int> visited(n, 0);
		for (j = 0; j < parties[i].size(); j++) {
			if (!visited[parties[i][j]] && dfs(parties[i][j], n, relations, visited, status)) {
				isLieable = false;
				break;
			}
		}
		if (isLieable) cnt++;
	}

	cout << cnt;
	return 0;
}
int dfs(int idx, int n, vector<vector<int>>& relations, vector<int>& visited, vector<int> &status){
	visited[idx] = 1;
	if (status[idx]) return 1;
	for (int i = 0; i < n; i++) {
		if (relations[idx][i] && !visited[i] && dfs(i, n, relations, visited, status)) {
			return 1;
		}
	}
	return 0;
}
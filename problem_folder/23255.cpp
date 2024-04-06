#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100000
#define MAX_EDGE 400
using namespace std;

/*
* ���Ͽ����ε�� ����� �ǹ��� �������� ������,
* �� ���տ��� �ǹ��� ������ ��ȣ ����������� ���� 1���� ������������ ĥ�ϴ� ����
* -> ������ �߸� ������
* > �����ٸ��� ����Ǿ� �ִ� �� �ǹ��� �ٸ� ������ ĥ�Ѵ�.
* -> ���� ����� �ǹ��� ���� �ٸ��� ��.
* 
* ���� - n���� ������ ���� �湮�Ҷ� �� ���� ����� �ٸ� ��� ������ ������ ������ �͵��� �����ϰ� ���� ������
* ���� ���� ������ �˾Ƴ��� �ϴµ�, �װ� ���� ����.
* O(NM)�� �ּҷ� ���� �� �ִ� �Ѱ�..
*/

// globals
int color[MAX] = { 0 };
vector<int> bridges[MAX];
set<int> available[MAX];


int main() {
	fastio;
	int n, m;	// n == nodeNum, m == edgeNum
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {	// i => iterates 0 from m
		int v, w;	// v, w => input 2 node Numbers
		cin >> v >> w;
		v--;
		w--;
		bridges[v].push_back(w);
		bridges[w].push_back(v);
	}
	
	// init available - O(400*n*logn)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < MAX_EDGE; j++) {
			available[i].insert(j + 1);
		}
	}
	// solving - O(2NMlgN)
	for (int i = 0; i < n; i++) {
		int bestColor = *(available[i].begin());
		color[i] = bestColor;
		// reflect it to other directly connected nodes
		for (int j = 0; j < bridges[i].size(); j++) {
			int nextIdx = bridges[i][j];
			available[nextIdx].erase(bestColor);
		}
	}
	
	// output
	for (int i = 0; i < n; i++) {
		cout << color[i] << " ";
	}

	return 0;
}
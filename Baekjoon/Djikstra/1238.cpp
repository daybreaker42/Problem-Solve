// Baekjoon No. 1238 ��Ƽ - 221109~ 221225
// Time Complexity
// ��������Ʈ ������� ���� (12/27)
#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF (int)2e9 + 7
#define SIZE 1000
using namespace std;

void dijkstra(int st, int n, vector<int> &dist, vector<vector<pair<int, int>>> &node);

int main() {
	fastIO
	int n, m, x, t, st, ed;
	int i, maxCost;
	cin >> n >> m >> x;
	vector<int> dist(n, INF);
	vector<int> res(n, 0);
	vector<vector<pair<int, int>>> node(n);
	vector<vector<pair<int, int>>> node_t(n);	// ��� �������� �ݴ�� ����
	
	// ��������Ʈ ��� ���
	for (i = 0; i < m; i++) {
		cin >> st >> ed >> t;
		node[st - 1].push_back({ ed - 1, t });	// { vertex - 1, weight }
		node_t[ed - 1].push_back({ st - 1, t });
	}

	// solving
	// ��ü -> x
	dijkstra(x - 1, n, dist, node_t);
	for (int i = 0; i < n; i++) {
		res[i] += dist[i];
	}

	// x -> ��ü
	// inits dist
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
	}
	dijkstra(x - 1, n, dist, node);
	for (int i = 0; i < n; i++) {
		res[i] += dist[i];
	}

	// output
	maxCost = 0;
	for (int dist : res) {
		maxCost = max(maxCost, dist);
	}
	cout << maxCost;
	return 0;
}

void dijkstra(int st, int n, vector<int>& dist, vector<vector<pair<int, int>>>& node){
	vector<bool> visited(n, 0);
	priority_queue<pair<int, int>> pq;
	int stIdx = st;
	dist[stIdx] = 0;
	pq.push({ -dist[stIdx], stIdx });
	while (!pq.empty()) {
		// �� �� �ִ� ���� �� �ּ� �Ÿ��� ���� ����
		stIdx = pq.top().second;
		while (visited[stIdx] && !pq.empty()) {
			pq.pop();
			if (!pq.empty()) stIdx = pq.top().second;
		}
		visited[stIdx] = true;
		
		// ���� ��忡�� �� �� �ִ� �ٸ� ������ distance ����
		for (int j = 0; j < node[stIdx].size(); j++) {
			int next = node[stIdx][j].first, weight = node[stIdx][j].second;
			if (!visited[next] && dist[next] > dist[stIdx] + weight) {
				// dist ���� ����
				dist[next] = dist[stIdx] + weight;
				pq.push({ -dist[next], next});
			}
		}
	}
	return;
}
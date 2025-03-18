#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int dfs(int n, vector<bool>& visited, vector<vector<int>>& graph);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++){
        int v, w;
        cin >> v >> w;
        v--;w--;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    // solving
    vector<bool> visited(n, false);
    int ans = dfs(0, visited, graph);

    cout << ans - 1;

	return 0;
}

int dfs(int n, vector<bool>& visited, vector<vector<int>>& graph){
    int result = 1;
    visited[n] = true;
    for(int next : graph[n]){
        if(!visited[next]){
            result += dfs(next, visited, graph);
        }
    }
    return result;
}

/* comment - 250215
- dfs를 통해 1번노드에 연결된 노드의 개수만 구하면 됐던 문제
- dfs에서 값을 return하지 않고도 visited[]에서 열린 개수만 세어줘도 정답을 구할 수 있다.


*/
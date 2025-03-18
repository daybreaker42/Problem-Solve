#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

void dfs(int n, vector<vector<int>>& node, vector<int>& parent, vector<bool>& visited){
    visited[n] = true;
    for(const int& next : node[n]){
        if(!visited[next]) {
            parent[next] = n;
            dfs(next, node, parent, visited);
        }
    }
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, 0);
    vector<vector<int>> node(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(1, node, parent, visited);

    for(int i = 2; i <= n; i++){
        cout << parent[i] << "\n";
    }
    

	return 0;
}

/* comment - 250313 / 10분
- 루트부터 트리를 탐색하면서 각 노드의 부모를 구해주면 되는 문제
- 부모 정보르 가져가야 하므로 dfs가 유리
- 트리 개념 잡기 좋은듯
*/
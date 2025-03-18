#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, q;
    cin >> n;
    vector<vector<int>> node(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    
    cin >> q;
    for(int i = 0; i < q; i++){
        int t, k;
        cin >> t >> k;
        if(t == 1){
            // edge node를 제외한 나머지 노드는 모두 단절점임
            if(node[k].size() > 1){
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }else{
            // 트리는 모든 간선이 단절선임
            cout << "yes\n";
        }
    }

	return 0;
}

/* comment 250313 / 8분
- 트리의 성질을 이용한 문제
트리 - 모든 간선이 단절선
연결된 노드 2개 이상인 모든 노드가 단절점 (모든 정점간 경로는 유일한 경로임)

*/
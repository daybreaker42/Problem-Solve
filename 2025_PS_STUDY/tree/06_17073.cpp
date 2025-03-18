#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int getLeafNodeNum(int curr, vector<bool>& visited, vector<vector<int>>& tree){
    int total = 0;
    visited[curr] = true;
    // 하위 리프노드 개수 count
    for(const int& next : tree[curr]){
        if(!visited[next]){
            total += getLeafNodeNum(next, visited, tree);
        }
    }
    if(total == 0){
        // 자식 없다면 현재 = 리프노드 return
        return 1;
    }
    return total;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, w;
    cin >> n >> w;
    vector<bool> visited(n + 1);
    vector<vector<int>> tree(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // solving
    int leafNodeNum = getLeafNodeNum(1, visited, tree);
    cout.precision(6);
    cout << fixed;
    cout << w / (double)leafNodeNum;

	return 0;
}

/* comment - 250318
1) 기댓값 총합 = w
결국 리프노드 개수 세서 w / leafNodeNum하면 되는 문제

- cout.precision()이랑 cout << fixed를 사용해야 맞는 문제..
- 안그러면 e-08 이런거 붙어서 나옴..(과학적 표기법)
- 소수 관련 출력 -> 항상 precision 및 fixed 사용하기
*/
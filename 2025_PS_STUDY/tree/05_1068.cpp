#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 50
using namespace std;

// const bool debug = false;
int parent[SIZE];

int getLeafNum(int curr, int remove, vector<vector<int>>& child){
    int total = 0;
    if(child[curr].size() == 0) return 1;
    else if(child[curr].size() == 1){
        int next = child[curr][0];
        if(next == remove) return 1;
        total += getLeafNum(next, remove, child);
    }else{
        for(const int& next : child[curr]){
            if(next != remove) total += getLeafNum(next, remove, child);
        }
    }
    return total;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);

    int n, remove, root;
    cin >> n;
    memset(parent, -1, sizeof(parent));
    vector<vector<int>> child(n);
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        parent[i] = val;
        if(val >= 0){
            // 부모가 있는 경우, 부모의 자식 리스트에 해당 노드를 추가함
            child[val].push_back(i);
        }else{
            // 부모가 없는 경우 -> root
            root = i;
        }
    }
    cin >> remove;

    // solving
    int ans = 0;
    if(root != remove){
        ans = getLeafNum(root, remove, child);
    }
    
    cout << ans;

	return 0;
}

/* comment 
1) dfs를 하는데 remove를 만났다면 제외하고(없는 셈 치고) dfs를 함
ㄴ solved!

2) dfs로 총 리프 노드 개수 1 구하고, remove부터 dfs해서 리프 노드 개수 2 구한 다음,
개수1 - 개수2하면 되는거 아닌가?
-> 개수1 - 개수2 + (지운거 부모 노드가 리프노드인지 여부)
*/
#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int getLength(int curr, int* pillarLength, int* branchLength, bool isBranch, vector<bool>& visited, vector<vector<pair<int, int>>>& tree){
    visited[curr] = true;
    if(!isBranch){
        // 현재 기둥일 경우
        // 기둥이 끝나는지 판단
        int childNum = 0;
        for(auto k : tree[curr]){
            int next = k.first; int length = k.second;
            if(!visited[next]){
                childNum++;
            }
        }

        if(childNum <= 1){
            // 다음것도 기둥일 경우
            int next = -1;
            for(auto k : tree[curr]){
                next = k.first; int length = k.second;
                if(!visited[next]){
                    // pillarlength 업데이트
                    *pillarLength += length;
                    // 다음 노드로 진행
                    getLength(next, pillarLength, branchLength, false, visited, tree);
                }
            }
        }else{
            // 다음부터 기둥이 아닌 경우 (현재 기가 노드)
            int maxLength = 0;
            for(auto k : tree[curr]){
                int next = k.first; int length = k.second;
                if(!visited[next]){
                    maxLength = max(maxLength, getLength(next, pillarLength, branchLength, true, visited, tree) + length);
                }
            }
            // branchlength 업데이트
            *branchLength = maxLength;
        }
        return 0;
    }else{
        // 현재 branch인 경우
        int maxLength = 0;
        for(auto k : tree[curr]){
            int next = k.first; int length = k.second;
            if(!visited[next]){
                maxLength = max(maxLength, getLength(next, pillarLength, branchLength, true, visited, tree) + length);
            }
        }
        return maxLength;
    }
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, root;
    cin >> n >> root;
    vector<bool> visited(n + 1);
    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back({b, d});
        tree[b].push_back({a, d});
    }

    // solving
    int pillarLength = 0, branchLength = 0;
    getLength(root, &pillarLength, &branchLength, false, visited, tree);
    cout << pillarLength << " " << branchLength;

	return 0;
}

/* comment - 250318
- 문제의 조건을 그대로 구현하면 되는 문제
1) 기가노드 도달 전까진 기둥 길이 ++
2) 기가노드 도달시 max branch length dfs로 구함
    - branch node일시 현재 노드에서 갈 수 있는 max length 반환


*/
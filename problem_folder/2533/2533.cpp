#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int getEarlyAdapterNum(int nodeIdx, bool isEA, int parentIdx, vector<vector<int>>& node);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> node(n, vector<int>());
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        node[u - 1].push_back(v - 1);
        node[v - 1].push_back(u - 1);
    }

    // solving
    int result = getEarlyAdapterNum(0, false, -1, node);
    result = min(result, getEarlyAdapterNum(0, true, -1, node));

    cout << result;

	return 0;
}

int getEarlyAdapterNum(int nodeIdx, bool isEA, int parentIdx, vector<vector<int>>& node){
    int eaCount = 0;
    for(int next : node[nodeIdx]){
        if(next != parentIdx){
            eaCount += getEarlyAdapterNum(next, !isEA, nodeIdx, node);
        }
    }
    if(isEA) eaCount++;
    return eaCount;
}

/* comment - 250211
아무 노드에서나 (1번 등) 시작하고, 해당 노드가 얼리어답터일 경우와 아닐 경우를 비교하면 됨.
특정 사람으로부터 시작해 해당 경우의 얼리어답터 수를 구하는 방법 -> dfs이용, 해당 노드가 얼리어답터인지의 정보만 주면 됨

*/

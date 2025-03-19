#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

struct node{
    int parent = -1;
    vector<pair<int, int>> childs;  // {child, weight}
};

int maxLength = 0;
node tree[10001];
vector<bool> visited(10001, false);

int dfs(int curr, int currWeight){
    visited[curr] = true;
    int maxDepth = 0, secondMaxDepth = 0;
    for(auto k : tree[curr].childs){
        int next = k.first, weight = k.second;
        if(!visited[next]){
            int depth = dfs(next, weight);
            if(depth > maxDepth){
                secondMaxDepth = maxDepth;
                maxDepth = depth;
            }
        }
    }
    maxLength = max(maxLength, maxDepth + secondMaxDepth);
    return currWeight + maxDepth;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, root = 1;
    cin >> n;
    // root = 1
    for(int i = 0; i < n - 1; i++){
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].childs.push_back({child, weight});
    }

    // solving
    dfs(root, 0);

    cout << maxLength;

	return 0;
}

/* comment 



*/
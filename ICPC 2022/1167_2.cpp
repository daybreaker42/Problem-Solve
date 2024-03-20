// Baekjoon No. 1167
// Time Complexity
// #

#include <iostream>
#include <vector>
using namespace std;

vector<int> dfs(vector<vector<int>>& node, vector<vector<int>>& weights, vector<int>& visited, int nodeIdx, int depth);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, v1, v2, tmp, weight;
    int i;
    cin >> v;
    vector<int> visited(v, 0);
    vector<vector<int>> node(v);
    vector<vector<int>> weights(v);
    for (i = 0; i < v; i++) {
        cin >> v1 >> v2 >> weight >> tmp;
        v1--;
        v2--;
        node[v1].push_back(v2);
        weights[v1].push_back(weight);
        while (tmp > 0) {
            v2 = tmp;
            cin >> weight;
            cin >> tmp;
            v2--;
            node[v1].push_back(v2);
            weights[v1].push_back(weight);
        }
    }

    // solve
    visited[0] = 1;
    vector<int> node_weight = dfs(node, weights, visited, 0, 0);
    // visited init
    for (i = 0; i < v; i++)
        visited[i] = 0;
    visited[node_weight[0]] = 1;
    node_weight = dfs(node, weights, visited, node_weight[0], 0);
    
    // output
    cout << node_weight[1];
    return 0;
}
vector<int> dfs(vector<vector<int>>& node, vector<vector<int>>& weights, vector<int>& visited, int nodeIdx, int depth) {
    int size = node[nodeIdx].size();
    vector<int> node_weight = { nodeIdx, depth }, tmp = {nodeIdx, depth};
    for (int i = 0; i < size; i++) {
        if (!visited[node[nodeIdx][i]]) {
            visited[node[nodeIdx][i]] = 1;
            tmp = dfs(node, weights, visited, node[nodeIdx][i], depth + weights[nodeIdx][i]);
            if (tmp[1] > node_weight[1]) {
                node_weight[0] = tmp[0];
                node_weight[1] = tmp[1];
            }
        }
    }
    return node_weight;
}
// Baekjoon No. 1167
// Time Complexity
// #

#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& node, vector<int>& visited, vector<vector<int>>& weights, vector<vector<int>>& max_depth, int nodeIdx);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, v1, v2, tmp, weight, tree_length;
    int i;
    cin >> v;
    vector<int> visited(v, 0);
    // vector<vector<int>> weights(v, vector<int>(v, 0));
    vector<vector<int>> weights(v);
    vector<vector<int>> node(v);
    vector<vector<int>> max_depth(v, vector<int>(2, 0));
    for (i = 0; i < v; i++) {
        cin >> v1 >> v2 >> weight;
        v1--;
        v2--;
        // node[idx]�� 2k-1��°�� nodeIdx, 2k��°�� weight
        node[v1].push_back(v2);
        weights[v1].push_back(weight);
        // node[v1].push_back(weight);
        cin >> tmp;
        while (tmp > 0) {
            v2 = tmp;
            v2--;
            cin >> weight;
            // save
            node[v1].push_back(v2);
            weights[v1].push_back(weight);
            cin >> tmp;
        }
    }

    // solve
    /** Ǯ�̹�
    1) ��Ʈ ��带 �ϳ� ���Ѵ�
    2) ��Ʈ ��忡������ dfs�� �� ����� ������ Ž��, ���� depth��Һ��� ũ�ٸ� �ִ� depth�� �����Ѵ�.
    3) max_depth�� ���� ��忡�� ���� �� �ִ� ���� �� ���� �� ���� 2���� �����Ѵ�.
    4) �� ��忡���� max_depth 2���� �յ� ��(�ڽ� node�� 1������ �ʱ�ȭ�� 0���� �Ǿ� �־� �������)
    ���� ū �� = �����̹Ƿ� ���� ���� ���� ����Ѵ�.
    */
    // root node = 0
    visited[0] = 1;
    dfs(node, visited, weights, max_depth, 0);
    // output
    tree_length = 0;
    for (i = 0; i < v; i++)
        if (max_depth[i][0] + max_depth[i][1] > tree_length)
            tree_length = max_depth[i][0] + max_depth[i][1];

    cout << tree_length;
    return 0;
}

// returns the biggest depth current node can go
int dfs(vector<vector<int>>& node, vector<int>& visited, vector<vector<int>>& weights, vector<vector<int>>& max_depth, int nodeIdx){
    int size = node[nodeIdx].size(), tmp_depth = 0;
    for (int i = 0; i < size; i ++) { // node[][]
        if (!visited[node[nodeIdx][i]]) {
            visited[node[nodeIdx][i]] = 1;
            tmp_depth = dfs(node, visited, weights, max_depth, node[nodeIdx][i]);
            if (max_depth[nodeIdx][1] < tmp_depth + weights[nodeIdx][i]) {
                max_depth[nodeIdx][1] = tmp_depth + weights[nodeIdx][i];
                if (max_depth[nodeIdx][0] < max_depth[nodeIdx][1]) {
                    int tmp = max_depth[nodeIdx][0];
                    max_depth[nodeIdx][0] = max_depth[nodeIdx][1];
                    max_depth[nodeIdx][1] = tmp;
                }
            }
        }
    }
    return max_depth[nodeIdx][0];
}
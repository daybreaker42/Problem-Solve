// Baekjoon No. 11725 Ʈ���� �θ� ã�� - 220923~220924
// Time Complexity O(n)
// #tree traversal, dfs

#include <iostream>
#include <vector>
using namespace std;

void disconnect(vector<vector<int>>& node, vector<int>& visited, int n,  int nodeIdx);   // �ش� nodeIdx�� ����� �θ�->�ڽ� ���� ������
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, child, parent;
    int i, j;
    cin >> n;
    vector<vector<int>>node(n);
    // map<int, vector<int>> node;
    vector<int> visited(n, 0);
    for (i = 0; i < n - 1; i++) {
        cin >> child >> parent;
        // �ϴ� �θ�->�ڽ� �ڽ�->�θ� ��� ����
        child--;
        parent--;
        
        node[child].push_back(parent);
        node[parent].push_back(child);
    }

    // solving
    /** �˰��� ����
    * 1) ��� �Է�, ���� ����� ����
    * 2) ��� 1���� DFS �����ϸ� �θ�->�ڽ� ���� ������
    * 3) ��� ���
    */
    disconnect(node, visited, n, 0);

    // output
    for (i = 1; i < n; i++) {
        for (j = 0; j < node[i].size(); j++) {
            if (node[i][j] >= 0) {
                cout << node[i][j] + 1<<"\n";
            }
            
        }
    }
    return 0;
}

void disconnect(vector<vector<int>>& node, vector<int>& visited, int n, int nodeIdx) {
    int i, size = node[nodeIdx].size(), nextIdx;
    // mark visited
    visited[nodeIdx] = 1;
    // finds if there is child node, and disconnects the connection
    // go to child node, and continues process
    for (i = 0; i < size; i++) {
        if (!visited[node[nodeIdx][i]] && node[nodeIdx][i] > 0) {
            nextIdx = node[nodeIdx][i];
            node[nodeIdx][i] = -1;
            disconnect(node, visited, n, nextIdx);
        }
    }
    return;
}
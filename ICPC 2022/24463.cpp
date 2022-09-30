// Baekjoon No. 24463 �̷� - 220917~
// Time Complexity O(n^2)
// #BFS

#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // input
    int n, m;
    int i, j;
    cin >> n >> m;
    vector<string> maze(n);
    for (i = 0; i < n; i++) {
        cin >> maze[i];
        for (j = 0; j < m; j++)
            if (maze[i][j] == '.')
                maze[i][j] = '@';
    }

    // solving
    // 1. bfs�� ��� Ž��. n^2
    // 1) ���۰� ���� ã��
    vector<vector<int>> answers; // ũ�� 2, 2�� �迭
    for (i = 0; i < n; i++) {
        if (maze[i][0] == '@')
            answers.push_back({ i, 0 });
        if (maze[i][m - 1] == '@')
            answers.push_back({ i, m - 1 });
    }
    for (j = 0; j < m; j++) {
        if (maze[0][j] == '@' && answers.size() < 2)
            answers.push_back({ 0, j });
        if (maze[n - 1][j] == '@' && answers.size() < 2)
            answers.push_back({ n - 1, j });
    }
    // answers print
    /*
    for (i = 0; i < answers.size(); i++)
        cout << answers[i][0] << " " << answers[i][1] << "\n";
    */


    // 2. ��ü �� @�� �ٲٱ� - n^2
    /*
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (maze[i][j] == '.')
                maze[i][j] = '@';
        }
    }
    */

    // 3. �ִܰ�� bfs�� ã��
    deque<deque<vector<int>>> queue;
    deque<vector<int>> current_path;
    vector<int> current_node;
    int row, col;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // ���� ��� push
    current_path.push_back({ answers[0][0], answers[0][1] });
    queue.push_back(current_path);
    
    while (queue.size() > 0) {
        current_path = queue.front();
        current_node = current_path.back();   // ������ ��忡 ����
        queue.pop_front();
        row = current_node[0];
        col = current_node[1];
        visited[row][col] = 1;

        // ������ �����ߴٸ�
        if (row == answers[1][0] && col == answers[1][1])
            break;

        // �ƴ϶�� �����¿� ���� �ִ� �� ��� ���� (�Ȱ� ��)
        vector<int>dx = { -1, 0, 1, 0 };
        vector<int>dy = { 0, -1, 0, 1 };
        for (i = 0; i < 4; i++) {
            if (row > 0 && maze[row + dx[i]][col + dy[i]] == '@' && !visited[row + dx[i]][col = dy[i]]) {
                current_path.push_back({ row + dx[i], col + dy[i] });
                queue.push_back(current_path);
                current_path.pop_back();
            }
        }
        /*
        if (row > 0 && maze[row - 1][col] == '@' && !visited[row - 1][col]) {
            current_path.push_back({ row - 1, col });
            queue.push_back(current_path);
            current_path.pop_back();
        }
        if (col > 0 && maze[row][col - 1] == '@' && !visited[row][col - 1]) {
            current_path.push_back({ row, col - 1 });
            queue.push_back(current_path);
            current_path.pop_back();
        }
        if (row < n - 1 && maze[row + 1][col] == '@' && !visited[row +1][col]) {
            current_path.push_back({ row + 1, col });
            queue.push_back(current_path);
            current_path.pop_back();
        }
        if (col < n - 1 && maze[row][col + 1] == '@' && !visited[row][col + 1]) {
            current_path.push_back({ row, col + 1 });
            queue.push_back(current_path);
            current_path.pop_back();
        }
        */
    }

    // 4. �ִܰ�θ� . ���� �ٲٱ� - n^2
    for (i = 0; i < current_path.size(); i++) {
        current_node = current_path[i];
        row = current_node[0];
        col = current_node[1];
        maze[row][col] = '.';
    }

    // 5. output
    for (i = 0; i < n; i++) {
        cout << maze[i] << "\n";
    }
    return 0;
}
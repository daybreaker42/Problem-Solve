// Baekjoon No. 9084 ���� - 220917 solved
// Time Complexity O(m)
// #DP
// ���� Ǯ���� 2293 ���� ������ �Ȱ���

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m;
    int i, j;
    cin >> t;
    for (int test = 0; test < t; test++) {
        // inputs
        cin >> n;
        vector<int> money(n);
        for (i = 0; i < n; i++) {
            cin >> money[i];
        }
        cin >> m;

        // solving
        vector<int> memory(m + 1, 0);
        memory[0] = 1;
        for (i = 0; i < n; i++) {   // money �ݺ�
            for (j = 0; j < m; j++) {   // memory ���鼭 �ݺ�
                if (memory[j] && money[i] + j<= m) {
                    memory[money[i] + j] += memory[j];
                }
            }
        }

        // outputs
        cout << memory[m] << "\n";
    }

    return 0;
}
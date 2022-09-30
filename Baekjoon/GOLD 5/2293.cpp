// Baekjoon No. 2293 ���� 1 - 220906~
// Time Complexity O(n*k)
// #DP
// ���� ���� �ߺ� x ������ �ݺ��� ��/�ܸ� �ٲ㼭 �ۼ��ߴٸ� Ǯ���� ����
// n�� k�� �ݺ��ϴ°Ŷ� k�� n�� �ݺ��ϴ� ���� �ٸ���.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    int i, j;
    cin >> n >> k;
    vector<int> values(n, 0);
    vector<int> memory(k + 1, 0);

    for (i = 0; i < n; i++)
        cin >> values[i];
            

    // solving
    memory[0] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            if (j + values[i] <= k)
                memory[j + values[i]] += memory[j];
        }
    }

    cout << memory[k];
    return 0;
}
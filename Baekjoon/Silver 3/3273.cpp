// Baekjoon No. 3273 �� ���� ��
// Time Complexity O(n)
// #DP
// ���� �ٸ� ���� n�� �� ���� �ٸ� 2���� ������ x�� ���� �� �ִ� ���� ����ϴ� ���α׷�

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    int i;
    cin >> n;
    vector<int> arr(n);
    for (i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    vector<int> memory(x + 1, 0);

    // solving
    for (i = 0; i < n; i++) {
        if(arr[i] < x)
            memory[arr[i]] = 1;
        if (x - arr[i] > 0 && arr[i] * 2 != x && memory[x - arr[i]])
            memory[x] ++;
    }
    cout << memory[x];

    return 0;
}
// Baekjoon No. 4929 ���� �ȱ� - 221024 solved
// Time Complexity O(n + m)
// #two pointer, math

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10000
using namespace std;

int arr1[SIZE] = { 0 };
int arr2[SIZE] = { 0 };

int main() {
    fastIO;
    int n1, n2, idx1, idx2;
    int sum1, sum2, res;
    int i;
    while (true) {
        idx1 = 0;
        idx2 = 0;
        sum1 = 0;
        sum2 = 0;
        res = 0;
        cin >> n1;
        if (n1 == 0) break;
        // arr1
        for (i = 0; i < n1; i++)
            cin >> arr1[i];
        // arr2
        cin >> n2;
        for (i = 0; i < n2; i++)
            cin >> arr2[i];
        
        // solving
        // sum ���ϱ�
        while (true) {
            // ���� ���� �ε����� ���� �ٴٶ��ٸ�
            if (idx1 == n1 && idx2 == n2) {
                res += max(sum1, sum2);
                break;
            }
            else if (idx1 == n1) {
                sum2 += arr2[idx2++];
            }
            else if (idx2 == n2) {
                sum1 += arr1[idx1++];
            }
            // �ε����� ���� �ٴٸ��� �� ��Ȳ�̶��
            if (idx1 < n1 && idx2 < n2) {
                if (arr1[idx1] == arr2[idx2]) {
                    sum1 += arr1[idx1++];
                    sum2 += arr2[idx2++];
                    res += max(sum1, sum2);
                    sum1 = 0;
                    sum2 = 0;
                }
                else if (arr1[idx1] > arr2[idx2]) {
                    sum2 += arr2[idx2++];
                }
                else {
                    sum1 += arr1[idx1++];
                }
            }   
        }
        cout << res << "\n";
    }
    return 0;
}
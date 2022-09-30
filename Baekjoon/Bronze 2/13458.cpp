// Baekjoon No. 13458 ���� ����
// Time Complexity O(n)
// int�� �ʰ��� �����ؾ� �ϴ� ����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, c, i; // ai -> �� �濡 �ִ� �����ڼ�, b - �Ѱ����� �����ο�, c - �ΰ����� �����ο�
    unsigned long long int minNum;
    cin >> n;
    vector<int> peopleNum(n, 0);
    for (i = 0; i < n; i++)
        cin >> peopleNum[i];
    cin >> b >> c;

    // solving
    // �Ѱ����� �� ���ϱ�
    minNum = n;
    // �ΰ����� �� ���ϱ�
    for (i = 0; i < n; i++) {
        peopleNum[i] -= b;
        if (peopleNum[i] > 0) {
            minNum += peopleNum[i] / c;
            if (peopleNum[i] % c > 0)
                minNum++;
        }
    }
    cout << minNum;
    return 0;
}
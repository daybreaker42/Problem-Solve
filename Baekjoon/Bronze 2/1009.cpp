// Baekjoon No. 1009 �л�ó�� - 220904 solved
// Time Complexity O(logn)
// �����ڸ������� n�������� ��Ģ���� �̿��� �ذ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <bitset>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b, res;
    int i, j;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> a >> b;
        int firstSeatNum = a % 10;
        b--;
        if (firstSeatNum == 0)
            res = 10;
        else if (firstSeatNum == 1)
            res = 1;
        else if (firstSeatNum == 2) {
            if (b % 4 == 0)
                res = 2;
            else if (b % 4 == 1)
                res = 4;
            else if (b % 4 == 2)
                res = 8;
            else if (b % 4 == 3)
                res = 6;
        }
        else if (firstSeatNum == 3) {
            if (b % 4 == 0)
                res = 3;
            else if (b % 4 == 1)
                res = 9;
            else if (b % 4 == 2)
                res = 7;
            else if (b % 4 == 3)
                res = 1;
        }
        else if (firstSeatNum == 4) {
            if (b % 2 == 0)
                res = 4;
            else
                res = 6;
        }
        else if (firstSeatNum == 5)
            res = 5;
        else if (firstSeatNum == 6)
            res = 6;
        else if (firstSeatNum == 7) {
            if (b % 4 == 0)
                res = 7;
            else if (b % 4 == 1)
                res = 9;
            else if (b % 4 == 2)
                res = 3;
            else if (b % 4 == 3)
                res = 1;
        }
        else if (firstSeatNum == 8) {
            if (b % 4 == 0)
                res = 8;
            else if (b % 4 == 1)
                res = 4;
            else if (b % 4 == 2)
                res = 2;
            else if (b % 4 == 3)
                res = 6;
        }
        else if (firstSeatNum == 9) {
            if (b % 2 == 0)
                res = 9;
            else
                res = 1;
        }

        cout << res << '\n';
    }
    return 0;
}
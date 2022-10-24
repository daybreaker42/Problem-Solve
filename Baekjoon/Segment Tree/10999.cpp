// Baekjoon No. 10999 ���� �� ���ϱ� 2 - 221022~
// Time Complexity O(nlogn)
// #Segment tree, ���� ��

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;

int n;
long long numbers[SIZE] = { 0 };
long long lazy[SIZE * 4] = { 0 };
long long segTree[SIZE * 4] = { 0 };

long long init(int, int, int);
long long query(int, int, int, int, int);
long long modify(int, int, int, int, int, long long);

int main() {
    fastIO
    int m, k, a, b, c;
    int i;
    long long d;
    cin >> n >> m >> k;
    for (i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // solving
    init(1, 1, n);
    for (i = 0; i < m + k; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            modify(1, 1, n, b, c, d);
        }
        else {
            cin >> b >> c;
            cout << query(1, 1, n, b, c) << "\n";
        }
    }
    return 0;
}

long long init(int nodeIdx, int st, int ed) {
    if (st == ed) return segTree[nodeIdx] = numbers[st - 1];
    int mid = (st + ed) / 2;
    long long left = init(nodeIdx * 2, st, mid);
    long long right = init(nodeIdx * 2 + 1, mid + 1, ed);
    return segTree[nodeIdx] = left + right;
}
long long query(int nodeIdx, int st, int ed, int l, int r) {
    int length = (ed - st + 1);
    // ������ �ִ� lazy�� ó��
    if (lazy[nodeIdx]) {
        segTree[nodeIdx] += lazy[nodeIdx] * length;
        if (st != ed) { // �ڽĳ�� �ִٸ�
            lazy[nodeIdx * 2] += lazy[nodeIdx];
            lazy[nodeIdx * 2 + 1] += lazy[nodeIdx];
        }
        lazy[nodeIdx] = 0;
    }
    if (ed < l || r < st) return 0;
    if (l <= st && ed <= r) return segTree[nodeIdx];
    int mid = (st + ed) / 2;
    long long left = query(nodeIdx * 2, st, mid, l, r);
    long long right = query(nodeIdx * 2 + 1, mid + 1, ed, l, r);
    return left + right;
}
// return���� ���� �ٲ��� ������ ����, �����ʿ� ���� ������ �� ���� ��. ���� ���̸� 0.
long long modify(int nodeIdx, int st, int ed, int l, int r, long long d) {
    int length = (ed - st + 1);
    // ������ �ִ� lazy�� ó��
    if (lazy[nodeIdx]) {
        segTree[nodeIdx] += lazy[nodeIdx] * length;
        if (st != ed) { // �ڽĳ�� �ִٸ�
            lazy[nodeIdx * 2] += lazy[nodeIdx];
            lazy[nodeIdx * 2 + 1] += lazy[nodeIdx];
        }
        lazy[nodeIdx] = 0;
    }
    if (ed < l || r < st) return 0; // ���� �����ִ� �� �����Ƿ� 0 return;
    if (l <= st && ed <= r) {
        // ���� �� �����ִ� �κ�, ���� �ڽ� ��� ��� ������ ���Ե� ��
        segTree[nodeIdx] += length * d;
        if (st != ed) { // �ڽĳ�� �ִٸ�
            lazy[nodeIdx * 2] += d;
            lazy[nodeIdx * 2 + 1] += d;
        }
        return length * d;
    }
    int mid = (st + ed) / 2;
    // ���� �ڽ� ���鿡�Լ� ������ ���� �� ���� ��忡 ������.
    long long leftVal = modify(nodeIdx * 2, st, mid, l, r, d);
    long long rightVal = modify(nodeIdx * 2 + 1, mid + 1, ed, l, r, d);
    segTree[nodeIdx] += leftVal + rightVal;
    return leftVal + rightVal;
}
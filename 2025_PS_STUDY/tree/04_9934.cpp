#include <bits/stdc++.h>
#define SIZE 2048
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int visitNum = 0;
int tree[SIZE];
int sequence[SIZE];

void inorder(int n, int k) {
    bool isRangeOver = n > (1 << k) - 1;   // 현재 노드 번호가 2^k - 1보다 크면 범위 벗어난 것.
    if (isRangeOver) return;

    inorder(n * 2, k);
    tree[n] = sequence[visitNum++];
    inorder(n * 2 + 1, k);
    return;
}

int main() {
    fastio;

    // freopen("../../input.txt", "r", stdin);
    int k; cin >> k;
    for (int i = 0; i < (1 << k) - 1; i++) {
        cin >> sequence[i];
    }

    // solving
    // 중위순회 하면서 tree 초기화
    inorder(1, k);

    // output
    int level = 1;
    for(int i = 1; i < (1 << k); i++){
        cout << tree[i] << " ";
        if(i == (1 << level) - 1){
            cout << "\n";
            level++;
        }
    }

    return 0;
}

/* comment - 250313
inorder로 순회한 결과롤 가지고 각 level에 있는 node의 번호를 순서대로 출력하는 문제

inorder - 왼쪽 -> 자신 -> 오른쪽
문제에선 완전 이진트리 가정

k주어졌다면, k값에 따라 완전이진트리 구성 가능

4
7 4 10 2 6 1 5 3 12 11 14 9 13 8 15
*/
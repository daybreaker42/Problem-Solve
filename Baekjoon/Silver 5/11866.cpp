// Baekjoon No. 11866 �似Ǫ�� ���� 0 - solved 220815
// Time Complexity O(n*k) ... �־� O(n^2)�ε� ��...
// n���� ����� ������ n�� ���ư��鼭 k��° ��� ����, �����ϱ⸦ �ݺ�.
// �׷��� ���� ���� ����ϴ� ����.
// linked list array�� �����ؼ� �ذ�
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, k, ptr, nextIdx, prevIdx;
    int i, j, index = 0;
    scanf("%d %d", &n, &k);
    vector<vector<int>> linkedLst(n, vector<int>(2, 0));
    vector<int> seq(n, 0);
    // init
    linkedLst[0][0] = n - 1;    // ���� idx
    linkedLst[0][1] = 1;        // ���� idx
    for(i = 1; i < n-1; i++){
        linkedLst[i][0] = i - 1;
        linkedLst[i][1] = i + 1;
    }
    linkedLst[n-1][0] = (n - 2) % n;    // 1 1 �Է¹����� [[0, 0]]���� �����Ǿ�� ��.
    linkedLst[n-1][1] = 0;
    
    // solve
    ptr = 0;
    index = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < k-1; j++)
            ptr = linkedLst[ptr][1];
        // ������ idx -> ptr
        seq[index] = ptr + 1;
        index++;
        nextIdx = linkedLst[ptr][1];
        prevIdx = linkedLst[ptr][0];
        
        
        // ������ ��� ���� ����� nextIdx���� ���� ��尡 ����Ű�� idx�� �ٲ���
        linkedLst[prevIdx][1] = nextIdx;
        linkedLst[nextIdx][0] = prevIdx;
        ptr = nextIdx;
    }
    // output
    printf("<");
    for(i = 0; i < n - 1; i++)
        printf("%d, ", seq[i]);
    printf("%d>", seq[n-1]);
    return 0;
}
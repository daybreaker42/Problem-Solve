// Baekjoon No. 10816 ī�� ��ȣ - 220815 solved
// Time Complexity O(n)
// Solved.ac # Class 1
// n���� ī�� ��ȣ�� �ް�, m���� �Է¿��� ���� �� ī�� ��ȣ�� �� �� �����ϴ��� ����ϴ� ���α׷�
// map�ڷ��� ����� ���� �ذ�. -> O(n) ���� �ذᰡ��.
// array ����ߴٸ� TC = O(m * n) �ɷ��� �����Ŷ� ����.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, m, tmp;
    int i;
    scanf("%d", &n);
    map<int, int> cards;
    for(i = 0; i < n; i++){
        scanf(" %d", &tmp);
        if(cards.find(tmp) == cards.end())  // �������� ���� ��
            cards[tmp] = 1;
        else    // key�� ������ ��
            cards[tmp]++;
    }
    
    scanf(" %d", &m);
    for(i = 0; i < m; i++){
        scanf(" %d", &tmp);
        printf("%d ", cards[tmp]);
    }   

    return 0;
}
// Baekjoon No. 11047 ���� 0 - 220825 solved.
// Time Complexity O(n)
// #Greedy
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, k, index, cnt;
    int i;
    scanf("%d %d", &n, &k);
    vector<int> coins(n, 0);
    for(i = 0; i < n; i++)
        scanf(" %d", &coins[i]);
    
    // solving
    /*
    1) ���� ���� 2�� �̻� ����� ���, �� ����� �ִٸ� ����� ��ü�� �� �ִ�.
    2) ��ü�� ����� ���� ���� �� ��찡 �������� ����̴�.
    ū ���� �ȵǸ� �׺��� ���� ���� ����� �� ���� ���� 1�� ���ԵǱ� ������ ������ �ش� ����.
    ���� �������� ���� �� ������(2) ū ���� ����� ��� (1)���� �� ������ ��찡 �ִٰ� �����ϸ�,
    ���� ���� ������ ����(2) �� ����� ū ���� �ִٸ�(3) �װɷ� ��ü�� �� �ְ�,
    ���ٸ� �� ���(2)�� ������ ����. ū ���� ����� ���(1) �� �������� �ʴ� ��.
    */
    cnt = 0;
    index = n - 1;
    while(index >= 0){
        if(k == 0)  // check����� �� �ݷ� ���̽�.
            break;
        if(k / coins[index] > 0){
            cnt += k / coins[index];
            k %= coins[index];
        }
        index --;
    }
    printf("%d", cnt);
    return 0;
}
// Baekjoon No. 24416 �Ǻ���ġ �� 1
// ��������� �Ǻ���ġ �Լ��� ������������ DP ������� ����������,
// ���� ����Ǵ� ������ Ƚ���� ���ϴ� �˰���
// ��������� ����Ǵ� Ƚ�� == ���� �Ǻ���ġ �� ���� �ű�����.
#include <iostream>
using namespace std;
int main(){
    int n, cnt1 = 0, cnt2 = 0, n_1 = 1, n_2 = 1;
    scanf("%d", &n);

    // ����
    for(int i = 0; i < n - 2; i++){
        cnt1 = n_1 + n_2;
        n_1 = n_2;
        n_2 = cnt1;
    }
    cnt2 = n - 2;

    printf("%d %d", cnt1, cnt2);
    return 0;
}
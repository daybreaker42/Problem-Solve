#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t, n, maxScore = 0, left_num;
    int i, j;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf(" %d", &n);
        left_num = n;
        maxScore = 0;
        
        // solving
        while(left_num > 0){
            left_num -= 2;  // bot
            maxScore += 1;

            left_num -= 3;
        }
        
        // output
        printf("Case #%d: %d\n", i+1, maxScore);
    }
    return 0;
}
// 5���϶� John�� bot�� ������ �ּҷ� ������� �� ���� 3ĭ�� ���� �����ϴٴ°� �˾���.
// ����ȭ��ų���� ������ ��������� ����
// 1 0 0 2 0 1
// 1 0 0 2 0
// 1 0 2 0
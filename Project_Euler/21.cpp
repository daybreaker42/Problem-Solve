// Project.Euler No. 21 / solved at 220730
// Time Complexity O(n^1.5)
#include <iostream>
#include <cmath>
using namespace std;
int d(int n);

int main(){
    int np = 0, sum = 0, end;
    cin >> end;                         // end ������ ��ּ� ���� ����.
    for(int i = 1; i <= end; i++){
        np = d(i);                      // d(a) == b
        if(d(np) == i && np != i){      // d(b) == a �̰� a != b�϶�
            sum += i + np;              // ���� ���� ������.
            printf("%d %d\n", i, np);   // �� ���� ���� ���
        }
    }
    sum /= 2;   // ���� ���� ���ϹǷ� ���� ���� ū �� �� ���� ������.
    cout << sum << endl;
    return 0;
}

// n�� ������ ��� ���� ����� ���� ��ȯ�ϴ� �Լ�
int d(int n){
    int sum = 0;
    if(n > 1) sum ++;   // d(1) = 0 �̹Ƿ�, ������ ���� 1�� ���������.
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            sum += i;
            sum += n / i;
        }
    }
    return sum;
}
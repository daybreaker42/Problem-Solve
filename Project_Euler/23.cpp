// Project Euler No. 23
// (28123 ������) �� ���׼��� ������ ��Ÿ�� �� ���� ��� ���� ������ ����?
// Time Complexity O(n^2)
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

#define MAX 30000
using namespace std;
int complete(int);

int main(){
    int overNum[MAX] = {0};     // ���׼� �����ϴ� �迭
    int integers[MAX] = {0};    // ���׼��� ���� �� �ִ� ������ �����ϴ� �迭
    int index = 0, sum = 0, cnt = 0; // index -> 30000 �̸��� ���׼� ����, sum -> �� ���׼��� ��Ÿ�� �� ���� ������ �� ����
    // ���� ����� ����
    // ofstream ofs("./completeNumbers.txt");
    // if(ofs.fail()){
    //     cout << "File Opening Failed\n";
    //     return -1;
    // }
    // ofs << "Hello, World!\n";
    // ofs << 1234 << endl;
    // ofs << 'a' << endl;
    
    // ���׼� �迭 �ʱ�ȭ, 30000 �̸��� ���׼� ��� ����
    for(int i = 1; i < MAX; i++)
        if(complete(i) > i)
            overNum[index++] = i;
    // ���׼� �迭 ���
    // for(int i = 0; i < index; i++){
    //     //     printf("%d ", overNum[i]);
    //     ofs << overNum[i] << " ";
    //     if(i % 20 == 0 && i > 0)
    //         ofs << endl;
    // }
    
    // ���׼� �ΰ��� ��Ÿ�� �� �ִ� ��� ���� ����. -> integers�� ����.
    for(int i = 0; i < index; i++){
        for(int j = i; j < index; j++){
            if(overNum[j] + overNum[i] < MAX && !integers[overNum[j] + overNum[i]])
                integers[overNum[j] + overNum[i]] = 1;
        }
    }

    // ���׼� �ΰ��� ���� �� ���� ���� �� ����.
    for(int i = 0; i < MAX; i++){
        if(!integers[i]){
            printf("%d ", i);
            sum += i;
            cnt ++;
        }
    }
    cout << endl << "���׼� ���� : " << index << endl;
    cout << "���׼� 2���� ���� �� ���� �� ���� : " << cnt << endl;
    cout << sum;
    cout << endl;
    return 0;
}
// �ڱ⸦ ������ ��� ����� ���� ��ȯ�ϴ� �Լ�
int complete(int n){
    int sum = -n;
    for(int i = 1; i <= sqrt(n); i++)
        if(n % i == 0 && i != n / i)    // n�� �����������϶��� i �ι� ������.
            sum += i + n / i;
    return sum;
}
// Baekjoon No. 11050 ���� ��� 1 - 220815 solved
// Time Complexity O(n)
// n, k�� �־��� �� nCk�� ���ϴ� ����
#include <iostream>
#include <vector>
using namespace std;
int fact(int n);
int main(){
    ios::sync_with_stdio(false);
    int n, k;
    scanf("%d %d", &n, &k);

    // nCk == n! / k! * (n-k)!
    printf("%d", fact(n) / (fact(k) * fact(n-k)));
    return 0;
}
int fact(int n){
    if(n <= 1)
        return 1;
    else
        return fact(n-1) * n;
}
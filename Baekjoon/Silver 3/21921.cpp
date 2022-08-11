// Basekjoon No. 21921 - ��α� / 0810 solved
// Time Complexity O(n)
// #���� ��, #�����̵� ������
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, x, maxVisits = 0, rangeCnt = 0, visits;
    int i, j, tmp;
    // inputs
    scanf("%d %d", &n, &x);
    vector<int> visitors(n, 0);
    scanf(" %d", &visitors[0]);
    for(i = 1; i < n; i++){
        scanf(" %d", &visitors[i]);
        visitors[i] += visitors[i-1];
    }

    // solving
    // n - x + 1 �� ����
    maxVisits = visitors[x-1];  // 1��
    rangeCnt = 1;
    for(i = 0; i < n - x; i++){ // n - x��
        visits = visitors[i+x] - visitors[i];
        if(maxVisits < visits){
            maxVisits = visits;
            rangeCnt = 1;
        }else if(maxVisits == visits)
            rangeCnt ++;
    }
    // outputs
    if(!maxVisits)
        printf("SAD");
    else
        printf("%d\n%d", maxVisits, rangeCnt);
    return 0;
}
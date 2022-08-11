// Baekjoon No. 7863 - Very Simple Problem / 0810 solved.
// n * p �Է��� ���� �迭 �� �� �࿡�� ���� ���� �ε����� ���� ������ ��,
// ���ݼ� �̻��� ���� ������ ���� �ε���+1�� ������������ ����ϴ� ����
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, p, minIdx, hrdIdx, cnt = 0;
    int i, j;
    scanf("%d %d", &n, &p);
    vector<vector<int>> ratings(n, vector<int>(p, 0));
    vector<int> simpleNumbers(p, 0);    // ���ڰ� �����ϴ� simplest idx ����
    
    for(i = 0; i < n; i++){
        for(j = 0; j < p; j++){
            scanf(" %d", &ratings[i][j]);
        }
    }

    // solving
    for(i = 0; i < n; i++){
        minIdx = 0;
        hrdIdx = 0;
        // ������ simplest idx ã��
        for(j = 1; j < p; j++){
            if(ratings[i][j] < ratings[i][minIdx]){
                minIdx = j;
            }
            if(ratings[i][j] > ratings[i][hrdIdx]){
                hrdIdx = j;
            }
        }
        // minIdx ���� �����͵� ���� ++��Ŵ
        for(j = 0; j < p; j++){
            if(ratings[i][j] == ratings[i][minIdx]){
                simpleNumbers[j] ++;
            }
            if(ratings[i][j] == ratings[i][hrdIdx]){
                simpleNumbers[j] -= n;  // ** point hardest �ϳ��� ������ �� �� ������ ��.
            }
        }
            
    }

    for(i = 0; i < n; i++){
        if(simpleNumbers[i] > n/2.0){
            printf("%d ", i+1);
            cnt++;
        }
    }
    if(!cnt)    // very simple �ϳ��� ������ 0 ���
        printf("0");
    return 0;
}
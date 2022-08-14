// Baekjoon No. 1007 - ���� ��Ī
// 
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m, t, i, j;
    long long int sx, sy;
    double result, minSum = -1.0;
    int vectors[20][2] = {0};
    scanf("%d", &t);

    // �� test case����
    for(i = 0; i < t; i++){
        sx = 0;
        sy = 0;
        result = 0;
        minSum = 0;
        scanf(" %d", &n);
        m = n / 2;  // m == n/2
        vector<int>combination(n);
        // combination -> 0���� n-1���� ������������ �������.
        for(int j = 0; j < n; j++)
            combination[j] = (j < m) ? 0 : 1;
        
        for(j = 0; j < n; j++)
            scanf(" %d %d", &vectors[j][0], &vectors[j][1]);
        
        minSum = -1;    // �ּ����̶�°� ����. �ִ������� �˾���..
        do{
            sx = 0;
            sy = 0;
            for(j = 0; j < n; j++){
                if(combination[j]){
                    sx += vectors[j][0];
                    sy += vectors[j][1];
                }else{
                    sx -= vectors[j][0];
                    sy -= vectors[j][1];
                }
            }
            if(sx + sy == 0)
                result = 0; // ��Ʈ0�� ������.
            else
                result = sqrt(pow(sx, 2) + pow(sy, 2));

            if(minSum > result || minSum < 0)
                minSum = result;
            
        }while(next_permutation(combination.begin(), combination.end()));
        // if(minSum < 0)
        //     minSum = 0;
        printf("%.12lf\n", minSum);
    }
    return 0;
}
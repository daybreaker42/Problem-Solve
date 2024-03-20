// Baekjoon No. 1004 - � ���� - 220815 solved
// ���������� �������� �̵��Ҷ� �ּ� �� ���� ���� ���� �� �ִ����� ���ϴ� ����.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int relation(int cx, int cy, int r, int x, int y);    // ���� ���� ���踦 �˷��ִ� �Լ�
int main(){
    ios::sync_with_stdio(false);
    int t, n, sx, sy, ex, ey, res;
    int i, tc;
    vector<vector<int>> circles(n, vector<int>(3, 0));
    scanf("%d", &t);
    for(tc = 0; tc < t; tc++){
        res = 0;
        scanf(" %d %d %d %d %d", &sx, &sy, &ex, &ey, &n);
        for(i = 0; i < n; i++)
            scanf(" %d %d %d", &circles[i][0], &circles[i][1], &circles[i][2]); // cx, cy, r ����
        
        // solving
        for(i = 0; i < n; i++){
            // �������̶� �������̶� �� ���� ����� �ٸ��ٸ� ++
            if(relation(circles[i][0], circles[i][1], circles[i][2], sx, sy) != relation(circles[i][0], circles[i][1], circles[i][2], ex, ey))
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
int relation(int cx, int cy, int r, int x, int y){
    double dist = 0;
    dist = sqrt(pow(cx - x, 2) + pow(cy - y, 2));
    // �Ÿ��� ���� ������ �������� ����. �������� ��迡 ��ģ ���� ���� �ʴ´ٰ� ��.
    if(dist > r)
        return 1;
    else
        return 0;
}
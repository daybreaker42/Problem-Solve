// Baekjoon No. 1697 ���ٲ��� - 220828 solved
// Time Complexity O(n)
// #DP #BFS-style
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, k, point;
    scanf("%d %d", &n, &k);
    if(k < n || k == n)
        printf("%d", n - k);
    else{
        vector<int> memory(2*k + 1, -1); // k ��°������ 2*k�� ����, �ȱ׷��� 2*k �̻��� ���� �� �� ����.
        queue<int> queue;
        queue.push(n);
        memory[n] = 0;
        while(memory[k] < 0){
            point = queue.front();
            queue.pop();
            if(point - 1 >= 0 && point - 1 <= 2*k && memory[point - 1] < 0){
                memory[point - 1] = memory[point] + 1;
                queue.push(point - 1);
            }
            if(point + 1 >= 0 && point + 1 <= 2*k && memory[point + 1] < 0){
                memory[point + 1] = memory[point] + 1;
                queue.push(point + 1);
            }
            if(point * 2 >= 0 && point * 2 <= 2*k && memory[point * 2] < 0){
                memory[point * 2] = memory[point] + 1;
                queue.push(point * 2);
            }
        }
        
        printf("%d", memory[k]);
    }
    return 0;
}
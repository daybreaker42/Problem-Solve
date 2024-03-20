// Baekjoon No. 1005 ACM Craft 0 220829~ 220831
// Time Complexity O(nlogn)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, k, w, check;
    int i, j, tc, tmp1, tmp2;
    scanf("%d", &t);

    for(tc = 0; tc < t; tc++){
        scanf(" %d %d", &n, &k);
        
        vector<int> time(n, 0);
        vector<int> memory(n, 0);  // �� ��帶�� ���µ� �ɸ��� �ð� ����
        vector<int> order;
        queue<int> queue;
        vector<vector<int>> graph(n+1, vector<int>(n, 0));    // ������ n+1��° ���� �� �� ���� �ջ��Ѱ� ����
        
        for(i = 0; i < n; i++)
            scanf(" %d", &time[i]);
        
        for(i = 0; i < k; i++){
            scanf(" %d %d", &tmp1, &tmp2);    // row -> col ����. => col ������ ���� ���ؾ� preBuild������ ������ ���� �� ����.
            graph[tmp1-1][tmp2-1] = 1;
            graph[n][tmp2-1]++;
        }
        
        scanf(" %d", &w);
        // solving - ���� ���� �̿�, ���� ���ؼ� dp ����ϱ�
        // ���� ���ϱ�
        for(i = 0; i < n; i++){
            if(!graph[n][i]){   // ����� ���� ���� == 0�� ��� �߰�
                queue.push(i);  // queue���� ����ȣ - 1 ���� �����.
            }
        }
        
        while(queue.size() > 0){
            check = queue.front();
            queue.pop();
            order.push_back(check); // queue�� �ִ� ��� �ϳ� ����
            for(i = 0; i < n; i++){ // pop�� ����� ���� ��� ����
                if(graph[check][i]){
                    graph[n][i]--;  // ���� graph ���� ����� �ǵ��� �ʰ� ����� ������ -= 1
                    if(graph[n][i] == 0){    // �ڽſ��� ����� ������ ��� ���ŵǾ��ٸ� ť�� �߰�
                        queue.push(i);  // �� ���� �߰��ؾ� �ϹǷ� �߰��Ȱ� ������ �ѱ�.
                        graph[n][i]--;
                    }
                }
            }
        }
        
        // dp �̿��� �� ���ϱ�
        // memory���� �� idx�� ��帶�� �ɸ��� �ð� ����
        // ���� ��� ��ȣ -> order[i] + 1
        for(i = 0; i < n; i++){
            if(i == 0){ // �� ó�� memory[0] ó���� ��
                memory[order[i]] = time[order[i]];
            }else{
                memory[order[i]] += time[order[i]];
                if(order[i] == w - 1)
                    break;
            }
            for (j = 0; j < n; j++) {
                if (graph[order[i]][j] && memory[j] < memory[order[i]]) {
                    memory[j] = memory[order[i]];
                }
            }
        }

        printf("%d\n", memory[w - 1]);
    }
    return 0;
}
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100000
using namespace std;

const bool debug = false;
bool visited[NUM] = {0};
int selection[NUM] = {0};

void check_group(int current, queue<int> &temp_queue);

// 241221 solved
int main() {
	fastio;
    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++){
            cin >> selection[i];
            selection[i] -= 1;
        }

        // solving
        int ans = n;
        
        fill(visited, visited + n, 0);  // visited[] init
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                queue<int> temp_queue = {}; // temp_queue init
                check_group(i, temp_queue);
                // 사이클이 만들어진 경우 - 사이클의 크기만큼 ans에서 빼준다.
                ans -= temp_queue.size();
            }
        }
        cout << ans << "\n";
    }

	return 0;
}

// dfs를 통해 사이클을 탐지해 큐에 저장하는 함수
void check_group(int current, queue<int> &temp_queue){
    int next = selection[current];
    temp_queue.push(current);
    visited[current] = true;
    // 다음 노드가 어떻게든 이미 방문되었다면
    if(visited[next]){
        // 방문된 노드를 큐의 최전방에 배치, 그 전에 방문했던 다른 노드들은 큐에서 모두 삭제.
        while(!temp_queue.empty() && temp_queue.front() != next){
            temp_queue.pop();
        }
        return;
    }
    // 다음 노드가 방문되지 않았다면 다음 노드로 이동
    check_group(next, temp_queue);
    return;
}
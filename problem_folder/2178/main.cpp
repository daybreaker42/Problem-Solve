#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

// const bool debug = false;
int delta[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};
typedef struct{
    int x;
    int y;
    int dist;
} node;

bool visited[SIZE][SIZE];
bool board[SIZE][SIZE];


int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for (int j = 0; j < m; j++){
            board[i][j] = str[j] - '0';
        }
        
    }
    queue<node> q;    // {x, y, dist};
    q.push({0, 0, 1});

    while(!q.empty()){
        node next = q.front();
        q.pop();
        // visited[next.y][next.x] = true;
        if(next.x == m - 1 && next.y == n - 1){
            // finished
            cout << next.dist;
            break;
        }
        for(int i = 0; i < 4; i++){
            int dx = delta[i][0], dy = delta[i][1];
            int nx = next.x + dx, ny = next.y + dy;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && board[ny][nx]){
                q.push({nx, ny, next.dist + 1});
                visited[ny][nx] = true;
            }
        }   
    }
	return 0;
}

/* comment - 0604 solved
- 큐에 넣을 때 visited 판단해야함
    - 그렇지 않으면 큐에 너무 많이 들어가 메모리초과
    - bfs라 제일 먼저 들어간게 제일 거리 짧음


*/
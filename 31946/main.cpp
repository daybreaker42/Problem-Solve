#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100
using namespace std;

// const bool debug = false;
int n, m, power;
bool board[SIZE][SIZE];
bool isVisited[SIZE][SIZE];

bool dfs(int x, int y);
int dist(int x1, int y1, int x2, int y2);

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    cin >> power;
    // solving
    bool isSuccess = false;;
    if(board[0][0] != board[n - 1][m - 1]){
        isSuccess = false;  // 시작이랑 끝이 다르면 애초에 불가
    }else{
        isSuccess = dfs(0, 0);
    }

    if(isSuccess){
        cout << "ALIVE";
    }else{
        cout << "DEAD";
    }

	return 0;
}

bool dfs(int x, int y){
    isVisited[y][x] = true;
    if(x == m - 1 && y == n - 1) return true;   // 종료 조건

    // 갈 수 있는 주변 power^2 면적의 주변 부분 보고, 갈 수 있으면 감.
    // 범위 안에 있으면서, board 위면서, 방문 안했으면서, 색 같은 경우
    for(int dx = -power; dx <= power; dx++){
        for(int dy = -power; dy <= power; dy++){
            int nx = x + dx, ny = y + dy;
            if(dist(x, y, nx, ny) <= power 
            && 0 <= nx && nx < m 
            && 0 <= ny && ny < n 
            && !isVisited[ny][nx] 
            && board[ny][nx] == board[y][x]){
                bool result = dfs(nx, ny);
                if(result){
                    return result;
                }
            }
        }
    }
    return false;    
}

int dist(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

/* comment 

2
2
0 0
0 1
5


5 3
0 0 0
1 1 0
0 0 0
0 1 1
0 0 0
1
*/
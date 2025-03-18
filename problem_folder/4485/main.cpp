#include <iostream>
#include <vector>
#include <queue>
#define INF 999999

using namespace std;

const vector<pair<int, int>> delta = {
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1}
};

bool checkCoord(int x, int y, int n){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main(){
    // freopen("../../input.txt", "r", stdin);
    int tc = 1;
    while(true){
        int n;
        cin >> n;
        if(n == 0) return 0;
        vector<vector<int>> cost(n, vector<int>(n));
        vector<vector<int>> dist(n, vector<int>(n, INF));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> cost[i][j];
            }   
        }
        // solving
        // int ans = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = cost[0][0];
        pq.push({dist[0][0], {0, 0}});
        while(!pq.empty()){
            pair<int, int> node = pq.top().second;
            int x = node.first, y = node.second;
            pq.pop();
            if(visited[y][x]) continue;     // 방문했었다면 pass
            visited[y][x] = true;
            for(int i = 0; i < 4; i++){
                int nx = x + delta[i].first, ny = y + delta[i].second;
                if(checkCoord(nx, ny, n)){
                    int newCost = dist[y][x] + cost[ny][nx];    // 현재까지의 cost + 다음 node cost 계산
                    if(!visited[ny][nx] && newCost < dist[ny][nx]){
                        dist[ny][nx] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        cout << "Problem " << tc << ": " << dist[n - 1][n - 1] << "\n";
        tc++;
    }
    return 0;
}

/* comment - 250221
시작점~목표지점 최단거리 -> 다익스트라 알고리즘 사용

- dist[0][0] != 0인 경우 조심 -> dist[0][0] 이 꼭 0은 아님.
*/
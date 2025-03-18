#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited);

int main(){

    // freopen("../../input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // solving
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bfs(i, graph, visited);
            ans++;
        }
    }

    cout << ans;
}

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : graph[curr]){
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return;
}

/* comment 250221
- dfs/bfs 문제
bfs로 해결
*/
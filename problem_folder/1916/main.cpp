#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
#define MAX 1000000007

using namespace std;

// const bool debug = false;
int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);    // {weight, nodeIdx}
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({w, v - 1});
    }
    int st, ed;
    cin >> st >> ed;
    st--; ed--;

    // solving
    vector<bool> visited(n, false);
    vector<int> dist(n, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[st] = 0;
    pq.push({dist[st], st});
    while(!pq.empty()){
        pair<int, int> topq = pq.top();
        pq.pop();
        int curr = topq.second, newCost = topq.first;
        if(visited[curr]) continue;     // 방문했었다면 skip
        visited[curr] = true;
        dist[curr] = newCost;

        for(int i = 0; i < graph[curr].size(); i++){
            int next = graph[curr][i].second, cost = graph[curr][i].first;
            if(!visited[next] && dist[next] > dist[curr] + cost){
                pq.push({dist[curr] + cost, next});
            }
        }
    }

    cout << dist[ed];

	return 0;
}

/* comment 250609, 자료구조 수업 다익스트라 예제 1



*/
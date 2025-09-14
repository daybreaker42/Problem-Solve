#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 800
using namespace std;

// const bool debug = false;
typedef struct{
    int weight;
    int nodeIdx;
}node;

int dist[SIZE];
vector<vector<node>> graph(SIZE);
void dijkstra(int st);

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, e; cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({w, v - 1});
        graph[v - 1].push_back({w, u - 1});
    }
    int v1, v2;
    cin >> v1 >> v2;
    v1--; v2--;

    // solving

	return 0;
}

void dijkstra(int st){

}

/* comment - 230609
idea1) 
st -> v1, v1 -> v2, v2 -> ed와
st -> v2, v2 -> v1 -> v1 -> ed로 가는 경로 각각 구해 비교

다익스트라 3번만 돌리면 됨 -> 
st->v1, st->v2
v1->v2, v1->ed
v2->v1, v2->ed



*/
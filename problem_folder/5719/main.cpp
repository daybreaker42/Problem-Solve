#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 2000000000
using namespace std;

// const bool debug = false;
typedef struct{
    int weight;
    int idx;
}node;


int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    while(n != 0 && m != 0){   
        int st, ed; cin >> st >> ed;
        vector<vector<node>> graph(n);

        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({w, v});
        }

        // solving
        vector<bool> isSPIncluded(n, false);
        vector<int> prev(n, -1);
        vector<int> dist(n, INF);
        priority_queue<node, vector<node>, greater<node>> pq;

        // 1. 일단 다익스트라 한 번 돌리면서 이전 노드 정보 저장
        dist[st] = 0;
        pq.push({dist[st], st});
        while(!pq.empty()){
            node curr = pq.top();
            if(dist[curr.idx] < curr.weight) continue;
            for(int i = 0; i < graph[curr.idx].size(); i++){
                int next = graph[curr.idx][i].idx;
                if(dist[next] > dist[curr.idx] + curr.weight){
                    dist[next] = dist[curr.idx] + curr.weight;
                    prev[next] = curr.idx;
                    pq.push({dist[next], next});
                }
            }
        }

        // 2. ed부터 st까지 가는 경로 탐색
        int curr = ed;
        set<pair<int, int>> spEdge;
        while(curr != st){
            if(curr == -1) {
                break;
            }
            spEdge.insert({prev[curr], curr});  // {이전 -> 이후} 형식으로 저장
            curr = prev[curr];
        }

        if(curr == -1){
            cout << -1;
            cout << "error - " << endl;
            continue;
        }
    }

	return 0;
}

/* comment - 250609
아이디어1)
일단 다익스트라 한 번 돌리면서 최단경로 구하고
인접행렬로 edge마다 최단경로에 사용됐는지 체크하는 2차원배열 만들어 사용된 경로 저장
    - 이 때 u->v 갱신하는 경우엔 갱신하면서 기존에 연결됐던거 끊어줘야 함
    - ->v로 오는 다른 경로들 다 끊어버리고 새로 추가하는 경로만 등록!
    - 그럼 노드별로 사용된 이전 경로(노드번호)만 저장하면 되지 않나?
        - (교수님 생각) 마지막 노드에서부터 백트래킹해서 시작 지점까지 돌아오면 구할 수 있음
그리고 다시 다익스트라 돌리면서 사용되지 않은 간선들에 대해서만 사용하면서 다익스트라 구성
만약 결과에서 dist[ed]가 INF라면 경로 없음 -> -1 출력



*/
#include <iostream>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

int find(int n, vector<int>& parent){
    if(n == parent[n]) return n;
    return parent[n] = find(parent[n], parent);
}

bool union_(int u, int v, vector<int>& parent){
    // if(u < v) swap(u, v);
    if(find(u, parent) == find(v, parent)) return false;
    int pu = find(u, parent), pv = find(v, parent);
    if(pu < pv) swap(pu, pv);
    parent[pv] = pu;
    return true;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<int> parent(v);
    vector<vector<pair<int, int>>> graph(v);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;    // {weight, {u, v}} 저장
    for(int i = 0; i < e; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--;
        graph[u].push_back({weight, v});
        graph[v].push_back({weight, u});
        pq.push({weight, {u, v}});
    }

    // solving
    int ans = 0;
    for(int i = 0; i < v; i++) parent[i] = i;   // parent init
    while(!pq.empty()){
        int weight = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        if(union_(u, v, parent)){
            ans += weight;
        }
    }
    cout << ans << "\n";
}

/* comment - 250221
MST 구하는 문제
#크루스칼 알고리즘 사용해서 해결
#유니온 파인드
*/
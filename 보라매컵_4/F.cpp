#include <bits/stdc++.h>
#define SIZE 200000
using namespace std;

int parent[SIZE];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool union_(int u, int v){
    int pu = find(u), pv = find(v);
    if(pu == pv) return false;
    if(pu < pv) swap(pu, pv);
    parent[pv] = pu;
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

    }
    // solving
    for(int i = 0; i < n; i++) parent[i] = i;
}

/* 250222
- 최단거리 경로 개수 문제...?
- 근데 개별 노선의 거리 <= 2^20만 -> ...? 최단경로 못구할거같은데

- 내가 무배경에서 MST를 생각해낼 수 있을까?

MST 가정하고 푼다면)
- 제일 비용 큰 순서대로 (크루스칼로) 제거해도 필수적 아니라면 상관 x. 어차피 무조건 그 길보다 효율적인 경로가 있음.


특징
- i번째 노선을 가는것보다 1~i-1 노선을 모두 타는게 더 효율적임

*/
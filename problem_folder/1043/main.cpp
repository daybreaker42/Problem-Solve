#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 51
using namespace std;

// const bool debug = false;

int parent[SIZE];

int find(int x){
    if(parent[x] == -1) return -1;   // -1 -> 모르는 사람 -> 자기 자신 return
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void union_(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX == rootY) return;
    if(rootX < rootY){
        parent[rootY] = rootX;
    }else{
        parent[rootX] = rootY;
    }
    return;
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    int truthNum;
    cin >> truthNum;
    for(int i = 0; i <= SIZE; i++){
        parent[i] = -1;         // 기본적으론 모두 모르는 사람 => -1로 초기화
    }
    int truthNum = -1;
    for(int i = 0; i < truthNum; i++){
        cin >> truthNum;
        parent[truthNum] = truthNum;
    }

    // solving
    for(int i = 0; i < m; i++){
        int total;
        int partyPeople[SIZE];
        for(int j = 0; j < total; j++){
            
        }
    }

	return 0;
}

/* comment 



*/
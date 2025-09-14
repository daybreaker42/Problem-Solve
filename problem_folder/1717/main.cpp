#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000001
using namespace std;

// const bool debug = false;

int parent[SIZE];

int find(int x){
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void union_(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rootX == rootY) return;
    // 더 작은 쪽에 합침
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
    for(int i = 0; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++){
        int flag, a, b;
        cin >> flag >> a >> b;
        if(flag){
            if(find(a) == find(b)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            union_(a, b);
        }
    }

	return 0;
}

/* comment 



*/
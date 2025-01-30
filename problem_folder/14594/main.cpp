#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool wall_exist[100] = {0}; // 각 방의 오른쪽 벽이 존재하는지 여부

int main() {
	fastio;
    int n, m;
    cin >> n >> m;

    fill(wall_exist, wall_exist + n, 1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        // solving
        for(int idx = x - 1; idx < y - 1; idx++){
            wall_exist[idx] = 0;
        }
    }

    // output
    int ans = 0;    // n번 방의 벽은 무조건 존재 -> 최소 방의 개수 = 1
    for(int i = 0; i < n; i++){
        if(wall_exist[i]){
            ans++;
        }
    }
    cout << ans;

	return 0;
}
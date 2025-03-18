#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 500
using namespace std;

// const bool debug = false;
int m, n;
short board[SIZE][SIZE];
int dp[SIZE][SIZE];

const pair<int, int> delta[] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

int dfs(int i, int j);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    // solving
    // dp[m - 1][n - 1] = 1;
    int ans = dfs(0, 0);

    // output
    cout << ans;

	return 0;
}

int dfs(int i, int j){
    if(dp[i][j] > 0) {
        // 방문한 곳은 다시 체크 x
        return dp[i][j];
    }else if(dp[i][j] < 0){
        return 0;
    }

    if(i == m - 1 && j == n - 1){
        // 목표 도착시
        return 1;
    }

    // int 
    // bool next = false;  // 다음에 갈 곳이 있는지 check
    for(int idx = 0; idx < 4; idx++){
        int nx = j + delta[idx].second, ny = i + delta[idx].first;
        if(0 <= nx && nx < n && 0 <= ny && ny < m && board[i][j] > board[ny][nx]){
            // next = true;
            dp[i][j] += dfs(ny, nx);
        }
    }
    if(dp[i][j] == 0) {
        dp[i][j] = -1;  // 답이 없는 곳은 -1로 체크
        return 0;
    }
    // if(!next) return 0;
    return dp[i][j];
}

/* comment - 250215
생각)
더 낮은 지점으로만 이동 가능 -> 높이차이 있을때 -> 사실상 방향 그래프로 생각 가능.

1. dfs로 안되나?

2. dp로 풀 수 있을 것 같음.
현재 지점의 경우의 수 = 이전 경로들의 경우의 수 합 으로 표현가능
근데 이러면 dfs랑 차이가 있나?
최소한 한번 갔던 경로는 dp[][]에 저장해놓으면 괜찮을듯?

- 여러번의 시도끝에 결국 solve
- 가서 정답인 곳만 저장할 것이 아닌 가서 막힌 곳도 따로 저장할 것. (그냥 visited는 모두 체크)
- edge case를 고려할 것 (m = n = 1인 경우 등)
*/
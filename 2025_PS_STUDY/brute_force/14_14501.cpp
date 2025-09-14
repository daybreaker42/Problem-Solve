#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 16
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);

    int n;
    cin >> n;
    int dp[SIZE];   // 각 일차에 받을 수 있는 최대 금액 저장
    int timeSpend[SIZE], reward[SIZE];
    int maxReward = 0;
    for(int i = 0; i < n; i++){
        cin >> timeSpend[i] >> reward[i];
    }

    // solving
    memset(dp, 0, SIZE * sizeof(int));
    for(int i = 0; i < n; i++){
        maxReward = max(maxReward, dp[i]);
        if(i + timeSpend[i] <= n && dp[i + timeSpend[i]] < maxReward + reward[i]){
            // 마지막 날짜 + 1일까지 저장
            dp[i + timeSpend[i]] = maxReward + reward[i];
        }
    }
    maxReward = max(maxReward, dp[n]);

    cout << maxReward;

	return 0;
}

/* comment - 250403 solved, 46분

1) n=15 ~= 32000 -> brute force로도 해결 가능
2) dp -> 이제까지 가능한 최대 가격을 계속 구하면 됨.
solved!


3
2 20
2 10
2 30

*/
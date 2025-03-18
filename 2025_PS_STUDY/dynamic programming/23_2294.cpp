#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100
#define MAX 10000
using namespace std;

// const bool debug = false;

int coins[NUM];
int dp[MAX + 1];

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, target;
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // solving
    // dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(coins[i] <= target) dp[coins[i]] = 1;
    }
    for(int i = 0; i <= target; i++){
        for(int j = 0; j < n; j++){
            int next = i + coins[j];
            if(dp[i] && next <= target){
                if(dp[next] != 0) dp[next] = min(dp[next], dp[i] + 1);
                else dp[next] = dp[i] + 1;
            }
        }
    }
    
    // output
    cout << (dp[target] > 0 ? dp[target] : -1);

	return 0;
}

/* comment - 250215
k를 만들 수 있는 최소 동전의 개수를 저장하면 되는 문제
- 매 경우를 시도하며 갱신 가능한 경우 갱신한다.
- 0일경우엔 무조건 갱신

주의
- 불가능한 경우 -1을 출력한다
*/
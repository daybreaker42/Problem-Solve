#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NUM 100
#define MAX 10000
using namespace std;

// const bool debug = false;

int dp[MAX + 1];
int coins[NUM];

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, target;
    cin >> n >> target;
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    // solving
    int result = 0;
    sort(coins, coins + n);         // 동전이 오름차순대로 안나오는 경우 방지
    
    dp[0] = 1;
    for (int c_idx = 0; c_idx < n; c_idx++){
        for (int i = 0; i < target; i++){
            if(!dp[i]) continue;
            
            int next = i + coins[c_idx];
            if(next <= target){
                dp[next] += dp[i];
            }
        
        }
    }

    // output    
    cout << dp[target];
    
	return 0;
}

/* comment 
- n * k 배열을 만들면 메모리 제한인 4mb에 걸릴 수 있음.

- 순서만 다르고 구성이 같은 경우 -> 같은 경우로 판단.
-> 조합이란 말인데..
-> 이전에 사용한 동전보다 더 큰 동전을 사용하게 하는건? -> 크거나 같아야 함. - 따로 배열 만들어 관리
ㄴ메모리초과: dp[i]에 i까지 올 수 있는 모든 경우의 수를 저장하니까 터짐 -> 경우의 수 <= 2^31이라 그럴수도
ㄴ마지막 수만 저장해도 마찬가지.

- 이전에 어떻게 풀었는지 봐봄
-> 동전이 겹치지 않게 -> n과 k 반복문의 배치를 바꿔주면 됨.
    - 일단 0번동전 사용해서 case 구성
    - 그 다음에 1번동전 사용해서 case구성
    ...
    - 이렇게 하면 동전을 사용할 때의 조합이 겹치지 않으면서도 효율적으로 값을 저장할 수 있음.
*/
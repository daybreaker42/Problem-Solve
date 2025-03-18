#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

struct promotion{
    int cost;
    int customer;
};

promotion promotions[20];
int dp[1001];               // dp[i] -> i명을 얻기 위해 투자해야 하는 최소 비용

int main() {
	// fastio;

	// freopen("input.txt", "r", stdin);
    int targetPeople, n;
    cin >> targetPeople >> n;
    for (int i = 0; i < n; i++){
        int cost, customer;
        cin >> cost >> customer;
        promotions[i] = {cost, customer};
    }
    
    // solving
    // init 
    // for (int i = 0; i < n; i++){
    //     if(dp[promotions[i].customer] == 0) dp[promotions[i].customer] = promotions[i].cost;
    //     else dp[promotions[i].customer] = min(dp[promotions[i].customer], promotions[i].cost);
    // }
    
    for (int i = 0; i <= targetPeople; i++){
        for(int j = 0; j < n; j++){
            int next = i + promotions[j].customer;
            next = min(targetPeople, next);
            if(dp[i] || i == 0){
                if(dp[next] == 0) dp[next] = dp[i] + promotions[j].cost;
                else dp[next] = min(dp[next], dp[i] + promotions[j].cost);
            }
        }
    }
    
    
    cout << dp[targetPeople];

	return 0;
}

/* comment - 250215
- 적어도 c명 -> c명 이상이어도 됨 -> 이 조건을 놓쳐서 시간을 좀 날렸음


*/
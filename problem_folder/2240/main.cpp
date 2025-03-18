#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {

	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t, w;
    cin >> t >> w;

    int prev = 0, num = 0;
    vector<vector<int>> arr(2);             // {{1번나무 떨어지는개수}, {2번나무떨어지는개수}}
    for(int i = 0; i < t; i++){
        int val;
        cin >> val;
        if(i == 0){
            prev = val;
            num++;
        }else if(prev != val){
            // 구간이 끝났을때 - 이전 구간의 개수는 이전 나무 배열에 추가, 다른 나무 배열엔 0 추가
            arr[prev - 1].push_back(num);
            arr[2 - prev].push_back(0);      // 다른 나무
            num = 1;
            prev = val;
        }else{
            num++;
        }
    }
    // 마지막일때
    arr[prev - 1].push_back(num);
    arr[2 - prev].push_back(0);      // 다른 나무

    // solving
    int length = arr[0].size(), currTree = 0; // currTree - 0, 1 -> 나무 1, 2
    vector<vector<int>> dp(length, vector<int>(w + 1));
    for(int j = 0; j <= w; j++){
        currTree = j % 2;
        for(int i = 0; i < length; i++){
            if(j < 1){
                if(i < 2){
                    dp[i][j] += arr[currTree][i];
                }else{
                    dp[i][j] += dp[i - 2][j] + arr[currTree][i];
                }
            }else{
                if(i < 1){
                    dp[i][j] += arr[currTree][i];
                }else if(i < 2){
                    dp[i][j] += dp[i - 1][j - 1] + arr[currTree][i];
                }else{
                    dp[i][j] = max(dp[i - 2][j], dp[i - 1][j - 1]) + arr[currTree][i];
                }
            }
        }
    }

    int maxNum = 0;
    if(length > 1){
        for(int i = 0; i <= w; i++){
            maxNum = max(maxNum, dp[length - 2][i]);
        }
    }
    for(int i = 0; i <= w; i++){
        maxNum = max(maxNum, dp[length - 1][i]);
    }
    cout << maxNum;

	return 0;
}

/* comment - 250221
idea) 각 나무에서 떨어지는 연속된 자두의 개수를 배열로 하는 w + 1개의 최대 연속 구간합을 구하는 문제
맨 앞 구간이 1의 구간이면 w + 1개 구간 가능, 2의 구간이면 w개 가능

-> 슬라이딩 윈도우?

'최대' w -> 길이 1일수도
-> 길이 1~ w+1까지의 최대 구간합 구하는 문제

ㄴ전혀 아니었음. 연속된 구간일 이유가 없었음.

-> 결국 dp
먼저, 이전 문제에서 했던것처럼 arr[]은 압축된채로 유지. (어차피 다른 나무에서 떨어질때만 이동하므로 그 사이는 생략 가능)
dp[i][j] -> i는 arr[i]일때, j는 w(이동횟수)
dp[i][j] = max(dp[i - 2][j], dp[i - 1][j - 1]) + arr[currTree][i]
    - arr[currTree][i]은 i턴에 currTree에서 몇개가 떨어지는지 표시

- 이번 dp는 좀 어려웠음.
- dp풀때 점화식부터 생각하는게 아니라, dp[]로 상태를 어떻게 표현할지 생각 -> 그리고 그 다음에 점화식은 dp[]요소들간에 관계를 나타내게 해주면 됨.

ex1)
t = 7, w = 2
arr - [1, 2, 2, 2]
tree - [2, 1, 2, 1]
*/
#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 200000
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, k; cin >> n >> k;
    int arr[SIZE];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // solving
    if(n <= k){
        cout << n;
    }else{
        int st = 0, ed = k;
        int countArr[100001];

        // 1. 0~k-1까지의 합을 미리 구하기
        int total = k;
        for(int i = 0; i < k; i++) {
            countArr[arr[i]]++;
        }
        // 2. k부터 시작
        while(ed < n){
            countArr[arr[ed]]++;
            while(countArr[arr[ed]] > k && st < ed){
                countArr[arr[st]]--;
                st++;
            }
            if(countArr[arr[ed]] <= k) total = max(total, ed - st + 1);
            ed++;
        }
        cout << total;
    }
    

	return 0;
}

/* comment - 250506 / 13분 37초
- 배열에서 각 원소가 k번 이하로 나오는 최장 연속 구간을 구하는 문제
- 처음엔 각 원소가 0~9까진걸로 착각했는데 ai <= 10^5라서 countArr의 범위를 늘려줘야 했음.
- n <= k면 return n을 할 수 있음
*/
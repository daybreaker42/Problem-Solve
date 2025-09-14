#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;

// const bool debug = false;
int arr[SIZE];

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n; cin >> n;
    int maxVal = 0;
    unordered_set<int> s;
    s.reserve(SIZE);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++){
        int iter = 1;
        long long aj = 2 * iter * arr[i] + (long long)iter * iter;
        while(aj <= SIZE && aj <= maxVal){
            if(s.find(aj) != s.end()){
                // cout << arr[i] << " | " << aj << endl;
                ans++;
            }
            iter++;
            aj = 2 * iter * arr[i] + (long long)iter * iter;
        }
    }
    cout << ans;

	return 0;
}

/* comment - 250513 solved
1. brute force - i, j 쌍 모두 찾기 - O(N^2)
2. ai^2 + aj = k^2, k^2 - ai^2 = aj, aj <=10^6, k > ai이므로, ai+1 ~ sqrt(10^6+ai)까지 k 돌려본다면?
- 배열 안에 있는지 확인 - set 사용 - O(1)
- k는 1씩 증가 -> k^2는 제곱으로 증가, sqrt(10^6) ~= 10^3 -> 약 10억?
- O(N * sqrt(N))?
-> 결국 k <= ai 라 O(N^2)임..
3. (ai + 1)^2 = ai^2 + 2ai + 1 ... aj = 2ai + 1이면 됨.
이후 2ai+1 + 2(ai+1)+1 + 2(ai+2)+1 + ... 으로 증가
-> 해당 과정 10^6 이하에서 반복하면 됨 -> 2ai씩 step 증가하므로 괜찮을지도
-> solved!! 정답을 찾으면 break를 걸어놨는데, 가능한 case가 더 있을 수도 있음!

** 주의 - arr가 4MB 차지 - 너무 커서 스택에 들어가지 않고 프로그램 종료됨;;
-> 전역 변수로 선언해서 heap 영역에 할당하니 됨.


2
3 16

2
3 7 16

*/
#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 10
using namespace std;

// const bool debug = false;

pair<int, int> ingredients[SIZE];   // {신맛, 쓴맛}
bool isSelected[SIZE];

long long getMinumDiff(int idx, int n);

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ingredients[i].first >> ingredients[i].second;
    }

    // solving
    memset(isSelected, 0, n);
    long long diff = getMinumDiff(0, n);
    cout << diff;

	return 0;
}

long long getMinumDiff(int idx, int n){
    if(idx == n){
        bool isUsed = false;
        long long totalMultiple = 1, totalSum = 0;
        for(int i = 0; i < n; i++){
            if(isSelected[i]){
                isUsed = true;
                totalMultiple *= ingredients[i].first;
                totalSum += ingredients[i].second;
            }
        }
        if(isUsed) return abs(totalMultiple - totalSum);
        else return -1;
    }
    
    isSelected[idx] = false;    // 해당 부분이 있어야 이전 step에서 돌아온 후, 제대로 초기화가 된 상태에서 다음 step으로 갈 수 있다.
    long long result1 = getMinumDiff(idx + 1, n);
    isSelected[idx] = true;
    long long result2 = getMinumDiff(idx + 1, n);

    // 둘 중 음수(불가능한 차이)가 있다면 반대 차이를 return하고, 없다면 더 작은 차이를 return한다.
    if(result1 < 0) return result2;
    else if(result2 < 0) return result1;
    else return min(result1, result2);
}

/* comment - 250503, 15분 / solved!
- N <= 10 -> 최대 1024번 -> brute force로 해결 가능
- 신맛, 쓴맛 <= 10^9 -> 계산시 int overflow 주의.

- 재귀를 이용해 2^N의 경우를 전부 순회한다.
*/

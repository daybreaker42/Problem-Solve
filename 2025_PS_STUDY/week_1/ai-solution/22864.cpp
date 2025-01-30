#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    fastio;
    
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    
    // 변수 초기화
    int work = 0;        // 총 일의 양
    int fatigue = 0;     // 현재 피로도
    
    // 24시간 동안 반복
    for(int hour = 0; hour < 24; hour++) {
        // 일할 수 있는 상태면 일하기
        if(fatigue + a <= m) {
            work += b;        // 일의 양 증가
            fatigue += a;     // 피로도 증가
        }
        // 일할 수 없으면 휴식
        else {
            fatigue = max(0, fatigue - c);  // 피로도 감소 (최소 0)
        }
    }
    
    cout << work;
    return 0;
}
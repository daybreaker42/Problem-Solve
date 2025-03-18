#include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
#define ll long long
using namespace std;

// const bool debug = false;

int check_time[SIZE];

ll binSearch(int n, int m, ll st, ll ed){
    if(st == ed) return st;
    ll mid = (st + ed) / 2;
    // 가능한지 검증, 안되면 mid + 1~ed, 되면 st~mid 검사
    ll total = 0;
    for(int i = 0; i < n; i++){
        total += mid / check_time[i];
    }
    if(total >= m) return binSearch(n, m, st, mid);
    else return binSearch(n, m, mid + 1, ed);
}

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> check_time[i];
    }
    
    // solving
    int minT = check_time[0];
    for (int i = 1; i < n; i++){
        minT = min(minT, check_time[i]);
    }
    
    ll ans = minT * m;  // 일단 무조건 해결가능한 시간 아무거나
    // ans = min(ans, binSearch(n, m, 0, MAX * MAX));
    ans = binSearch(n, m, 1, ans);

    // output
    cout << ans;

	return 0;
}

/* comment 
- 최악의 시간이 걸릴 경우 -> n=1, m=10억, t1=10억 -> 10^18 걸림 -> long long 사용

생각)
- 그리디? 
naive하게 생각하면 정답 -> max(t1 * x1, t2 * x2, ...) 를 최소로 하는 x1, ... xi 구하는거. (이때 sigma(xi) == m)
- 인기있는 애들은 계속 진행할수밖에 없음 -> 빨리 끝내주는 애들이 노는 일은 없음
- 시간이 제일 오래 걸리는애가 기다리기까지 해서 마지막에 끝내는 경우는 x
기다리면서 들어가는거 -> 무조건 더 빨리 끝나는 창구.


n == 1)
정답 -> m / ti + (나머지있으면 1)
t1 * x1 => ans, t1 * m = m

n == 2)
정답 => max(t1 * x1, t2 * x2)가 최소일때의 값, x1 + x2 = m


어느 경우에도 해결가능 -> m * min(ti) = 무조건 해결가능한 시간
그렇다면, 반대로 시간을 주고, 해당 시간에 해결할 수 있는 양 (x)를 구하면?
-> 찾아가는 과정 - 이분탐색 이용
-> 총 반복횟수 -> log(M*Tk), 반복당 연산횟수 -> O(N) -> O(N * log(M * Tk))
이때 M * Tk <= 10^18, N <= 10^5 이므로 가능?
*/
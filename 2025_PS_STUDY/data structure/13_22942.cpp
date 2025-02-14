#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

struct circle {
    int idx;
    int status;
};

map<int, circle> x_axis;   // {좌표, {원 번호, 상태}} / 상태 : 시작 = 1, 종료 = 2

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int c, r, st, ed;
        cin >> c >> r;
        st = c - r; ed = c + r;
        // circles[i] = {st, ed, i};
        if(x_axis.find(st) != x_axis.end() || x_axis.find(ed) != x_axis.end()){
            // 애초에 겹치는 좌표가 있었을 경우 - 시작부터 안됨
            cout << "NO";
            return 0;
        }
        x_axis[st] = {i, 1};    // map에 삽입 -> O(lgN)
        x_axis[ed] = {i, 2};
    }

    // solving
    stack<int> s;   // 현재 열려있는 원 번호, 열려있는것만 들어감.
    for(const auto c : x_axis){
        int circleIdx = c.second.idx, status = c.second.status;
        if(status == 1){
            s.push(circleIdx);
        }else{
            if(s.empty()){
                // 원의 시작은 없는데 끝나버린 경우
                cout << "NO";
                return 0;
            }
            if(s.top() != circleIdx){
                // 한 원이 끝나지 않았는데 다른 원이 시작될 경우
                cout << "NO";
                return 0;
            }
            s.pop();
        }
    }

    cout << "YES";

	return 0;
}

/* comment - 250214
0) 수직선 위에 있는 두 원이 겹치지 않을을 조건: 
    1. |c1 - c2| <= r1 + r2 
    2. c2 - r2 < c1 - r1 && c2 + r1 < c2 + r2   // r2 > r1 일때
1) naive하게 생각했을떄, 한 원이 다른 모든 원에 대해 겹치지 않으면 됨. -> O(N^2), n <= 200000이므로 X
2) 한쪽 방향에서 다른 방향으로 진행하면서, x좌표가 겹치는 원들끼리만 검사하면 됨 -> 근데 이거 괄호랑 다를게 없는데?
    - 원들의 시작 좌표를 각각 저장, 순서대로 반복하면서 스택에 넣으면서 원이 끝나면 스택에서 뺌
    - 그 사이에 다른 원이 먼저 끝나버리면 -> x

결론
원의 위치관계로 생각해도 풀 수 있지만, 문제를 조금 멀리서 보면 괄호 문제랑 다를게 없다는 걸 알 수 있었다.
*/
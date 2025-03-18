#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    stack<int> s;
    int building_num = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        while(!s.empty() && s.top() >= y){
            if(s.top() > y) building_num++;
            s.pop();
        }
        if(y > 0) s.push(y); 
    }

    // 마지막에 0으로 끝나면 이거 필요없음. 그러지 않는 경우도 있어서 스택 비워주는 부분 추가
    while(!s.empty()){
        building_num++;
        s.pop();
    }

    cout << building_num;

	return 0;
}

/* comment - 250215
- input보다가 y값이 작아질 때 건물을 ++하는 방향으로 가면 어떨까 하고 생각
- test case 보다보니 꽤나 말이 돼서 그대로 실행
- 정답 맞음

- idea) stack이용
    - 현재값보다 크면 빼면서 빌딩수 += 1, 같은건 중복되니까 일단 뺌
    - 현재값보다 작으면 현재값 push (0이면 건물 없으므로 push x)
    - 

*/
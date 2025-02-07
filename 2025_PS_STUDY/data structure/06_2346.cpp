#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    deque<pair<int, int>> dq;
    int next = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        dq.push_back({i + 1, num}); // {풍선 번호, 이동 번호}
    }

    while(!dq.empty()){
        if(next == 0){
            next = dq.front().second;
            cout << dq.front().first << "\n";
            dq.pop_front();
            if(next > 0) next--;    // 자료구조 특성상 next > 0일땐 바로 가리키고 있으므로 하나를 빼줌
        }else if(next > 0){
            dq.push_back(dq.front());
            dq.pop_front();
            next--;
        }else{
            dq.push_front(dq.back());
            dq.pop_back();
            next++;
        }
    }

	return 0;
}

/* comment 250207 
- 요새푸스 문제와 비슷한 형식
- 다만 새로 숫자를 받고 오른쪽으로 가야 할 땐 이미 다음 숫자를 가리키고 있으므로(pop) 하나를 빼줘야 함.
*/
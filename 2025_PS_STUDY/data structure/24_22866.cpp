#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 100000
using namespace std;

// const bool debug = false;

int height[SIZE];           // 건물 높이 저장
int visible_count[SIZE];    // 건물당 볼 수 있는 건물 개수 저장
int near_building[SIZE];    // 가장 가까우면서 번호가 작은 빌딩 번호 저장

int main() {
    fastio;

    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }

    // solve
    memset(near_building, -1, sizeof(near_building));

    // 오른쪽에 위치하는 볼 수 있는 건물 번호 구하기
    stack<int> s;       // 건물 번호 저장, 오름차순
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && height[s.top()] <= height[i]){
            s.pop();
        }
        if(!s.empty() && (near_building[i] < 0 || abs(i - s.top()) <= abs(i - near_building[i]))){
            near_building[i] = s.top();
        }
        visible_count[i] += s.size();
        s.push(i);
    }

    s = stack<int>();

    // 왼쪽에 위치하는 볼 수 있는 왼쪽 건물 번호 구하기
    for (int i = 0; i < n; i++){
        while(!s.empty() && height[s.top()] <= height[i]){
            s.pop();
        }
        if(!s.empty() && (near_building[i] < 0 || abs(i - s.top()) <= abs(i - near_building[i]))){
            near_building[i] = s.top();
        }
        visible_count[i] += s.size();
        s.push(i);
    }
    
    // output
    for(int i = 0; i < n; i++){
        cout << visible_count[i];
        if(visible_count[i] > 0){
            cout << " " << near_building[i] + 1;
        }
        cout << "\n";
    }

    return 0;
}

/* comment  250211

idea) 이전에도 비슷한 문제 푼 적 있었음. 아마 왼쪽에 볼 수 있는게 몇개인지 세는 문제.
풀이 아이디어는 한 뱡향씩 배열 순회하면서, stack에 자신보다 작은 수가 나올때까지
ㄴ시간초과

2트) deque으로 바꾸고 try - 틀림

3트) deque이랑 stack이랑 별 차이가 없다는 걸 찾음. 결국 stack은 오름차순으로 저장했어야 했던거임.
그거랑 `near_building[i] < 0` 이 부분에서 near_building말고 visible_count를 써서 틀렸었음.
실수 고치니 solved.
*/
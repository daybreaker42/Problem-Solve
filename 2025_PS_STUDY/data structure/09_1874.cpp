#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // solving
    int idx = 0;
    stack<int> s;
    vector<char> turn;
    for (int i = 1; i <= n; i++){
        s.push(i);
        turn.push_back('+');
        while(!s.empty() && s.top() == arr[idx]){
            s.pop();
            turn.push_back('-');
            idx++;
        }
    }

    if(s.empty()){
        for (char c : turn){
            cout << c << "\n";
        }
    }else{
        cout << "NO";
    }
    

	return 0;
}

/* comment - 250208
- 그냥 순서대로 스택에 채우면서 만약 방금 채운 숫자가 array에서 출력해야 할 숫자라면 출력
- 그 결과를 기록
- 마지막에 스택이 비어있다면 성공, 그렇지 않다면 실패

실패하는 경우
- 지금 뺄 수 있는 수랑 지금 빼야 하는 수랑 다른데, 지금 앞에 있는 수를 지금 빼면 안되는 경우

*/
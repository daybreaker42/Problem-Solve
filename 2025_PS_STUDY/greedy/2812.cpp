#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, k; cin >> n >> k;
    string number; cin >> number;
    int left_pop = k;
    deque<int> s;       // back에서 삽입해서 front로 나옴
    for(int i = 0; i < n; i++){
        char c = number[i];
        int num = c - '0';
        while(!s.empty() && s.back() < num && left_pop > 0){
            // 갑자기 증가하는 부분 나왔는데, 아직 지울 수 있으면 해당 수 지우고 
            s.pop_back();
            left_pop--;
        }
        // 단조 감소하거나, 지울거 다 지웠으면 숫자 계속 추가
        s.push_back(num);
    }

    for(int i = 0; i < n - k; i++){
        cout << s.front();
        s.pop_front();
    }

	return 0;
}

/* comment - 250501
아이디어
- 앞에서부터 작은 수를 지워야 함.
- 결국 n - k자리가 될 거라면, 사전순으로 가장 뒤에 오는 수를 찾아야 함 -> 앞자리가 제일 커야 함.
- 만약 앞쪽부터 순회하면서 오름차순으로 수열이 나왔을 떄, 지울 수 있는 수가 있다면 이전 수를 지우는게 이득. (해당 자리에 올 수 있는 더 큰 수)

풀이
- 모노톤 스택의 성질을 활용해 풀이 가능
- 계속 감소하는 방향으로 수가 만들어져야 이득.
- 증가하는 구간이 나왔다면, 앞에서부터 제거하는게 이득. -> stack 활용
- 마지막엔 들어온 순서대로 처리해야함 -> deque 이용
*/
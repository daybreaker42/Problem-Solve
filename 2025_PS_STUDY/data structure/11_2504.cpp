#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pil pair<int, ll>

using namespace std;

// const bool debug = false;

// 각 괄호의 짝이 되는 괄호 저장
map<char, char> other_side = {
	{'(', ')'},
	{'[', ']'},
	{')', '('},
	{']', '['},
};
// 각 괄호당 할당된 값들 저장
map<char, int> weight = {
	{'(', 2},
	{')', 2},
	{'[', 3},
	{']', 3},
};

// pil -> {endIdx, returnVal}
pil oper(int idx, char start, string& str);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

	string str;
	cin >> str;

	// solving
	int endIdx = 0;
	ll ans = 0;
	ll returnVal;
	// 전체 문자열이 괄호로 묶여있지 않기 때문에 for로 한번 감싸줌
	for(int i = 0; i < str.length(); i++){
		tie(endIdx, returnVal) = oper(i, str[i], str);
		if(returnVal < 0){
			// 적합하지 않게 끝난 경우
			ans = -1;
			break;
		}
		ans += returnVal;
		i = endIdx;
	}

	// output
	cout << (ans < 0 ? 0 : ans);
	
	return 0;
}

// 한 괄호 안에 있는 결과를 연산에서 return하는 함수
// 적합하지 않은 부분 발견시 {-1, -1} return
pil oper(int idx, char start, string& str){
	int length = str.length();
	ll tmp = 0;

	for(int i = idx + 1; i < length; i++){
		char curr = str[i];
		if(curr == '(' || curr == '['){
			// 시작
			int endIdx;
			ll returnVal;
			tie(endIdx, returnVal) = oper(i, curr, str);
			if(returnVal < 0) return {-1, -1};	// 적합하지 않은 부분이 있다면 -> -1 return
			tmp += returnVal;
			i = endIdx;	// i -> 다음 시작점 이전으로 이동
		}else if(other_side[curr] == start){
			// 끝 - 적합하게 끝난 경우
			tmp *= weight[curr];
			if(tmp == 0) tmp = weight[curr];	// 괄호 안에 아무것도 없는 경우 -> 그 자체로 값이 되는 2, 3 return
			return {i, tmp};
		}else{
			// 적합하지 않게 끝난 경우
			return {-1, -1};
		}
	}
	// for문에 들어가지 못한 경우 - out of range
	return {-1, -1};
}

/* comment - 250215
주의
- 문자열 길이 <= 30 -> ans <= 3^30 ~= 2*10^14 -> int 넘어갈수도 -> long long 사용

알고리즘
1. (나 [으로 시작시 스택에 쌓음
2. )나 ]으로 종료시(같은 문자로) 이제까지 쌓은 값에 * 2, 3을 해서 return. 만약 값이 없다면 2, 3 return
3. 도중에 불완전하게 종료되면 -1 return
*/
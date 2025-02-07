#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    string str;
    cin >> str;

    ll ironPlaced = 0, ans = 0;
    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        if(c == '(' && i < str.length() - 1 && str[i + 1] == ')'){
            // 레이져인 경우
            ans += ironPlaced;
            i++;
        }else if(c == '('){
            ironPlaced++;
        }else{
            ironPlaced--;
            ans++;
        }
    }

    cout << ans;

	return 0;
}

/* comment
- 레이져인 경우 -> 현재 겹쳐 있는 쇠막대기의 개수만큼 조각이 새로 생김
- 괄호를 닫는 경우 -> 쇠막대기가 끝남 -> 조각이 하나 더 생김 (2개로 쪼개면 3개가 생김; 쇠막대기의 끝은 겹치지 않음)

- long long 사용한 이유 -> 최대 10만개 string이면 레이져5만에 막대기 5만개가 있을 수 있다고 생각 -> 25억으로 int 범위 초과.
다시 생각해보니 쇠막대기 하나당 괄호 2개 필요, 레이져도 마찬가지. 각각 최대 2.5만개씩 => 6.2억으로 int 범위내.
*/
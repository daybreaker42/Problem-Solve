#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while(t-- > 0){
        string str;
        cin >> str;
        // check VPS
        stack<char> s;
        bool isVPS = true;
        for(char c : str){
            if(c == '('){
                s.push(c);
            }else{
                if(!s.empty()){
                    s.pop();
                }else{
                    isVPS = false;
                    break;
                }
            }
        }

        if(isVPS && s.empty()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

	return 0;
}

/* comment - 250207
- 괄호가 시작되면 스택에 괄호를 넣고, 끝나면 하나씩 뺌
- 중간에 뺄 괄호가 없는데 빼야 하는 상황이 생기거나, 종료된 이후에도 스택에 괄호가 남아있으면 VPS가 아님
*/
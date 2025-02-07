#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

// 연산자 우선순위 지정
map<char, int> priority = {
    {'(', 3},
    {')', 3},
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
};

string result;
stack<string> variable;
stack<char> oper;

void operStart() {
    string v1 = variable.top(), v2;
    variable.pop();
    v2 = variable.top();
    variable.pop();
    variable.push(v2 + v1 + oper.top());
    oper.pop();
}

int main() {
    fastio;

    // freopen("input.txt", "r", stdin);

    string exp;
    cin >> exp;

    // solving
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isalpha(c)) {
            variable.push({ c });
        }
        else {
            if (!oper.empty() && priority[oper.top()] >= priority[c]) {
                while(!oper.empty() && priority[oper.top()] >= priority[c]){
                    if (oper.top() == '(') {
                        break;
                    }
                    operStart();
                }

                if(c == ')'){   // 이거때문에 마지막에 고생 - 여기에 )는 오면 안됨
                    oper.pop();
                }else{
                    oper.push(c);
                }
            }
            else if (oper.empty()) {
                // oper가 비어있는 경우
                oper.push(c);
            }
            else {
                // oper에 값이 있는데 c가 그것보다 우선순위가 높을 경우
                if (c == ')') {
                    do {
                        operStart();
                    } while (oper.top() != '(');
                    oper.pop();
                }
                else {
                    oper.push(c);
                }
            }
        }
    }

    while (!oper.empty()) {
        operStart();
    }

    cout << variable.top() << endl;

    return 0;
}

/* comments
idea)
스택 두개를 이용해 각각 알파벳, 연산자를 처리
- 알파벳이 들어올 경우 -> 스택에 항상 넣음
- 연산자가 들어올 경우
    - 이전에 연산자가 있는데 그거랑 우선순위가 같거나 더 작은 경우 -> 이전 연산 수행 (조건을 만족하는 한), 괗로 만나면 멈춤
        - 그리고 만약 다음에 오는게 )만 아니면 스택에 넣고 계속 진행
    - oper가 비어있는 경우 -> 다음에 뭐가 올지 모르므로 keep
    - oper에 값이 있는데 그것보다 더 우선순위가 높은 경우 -> 
        - )이 나온거면 clear 진행
        - 다른거면 keep
- 마지막에 한번 스택 싹 비워줌

-> 재귀함수로 할 수 있을 것 같은데...


바로 처리할 수 있는 경우
다음
*/
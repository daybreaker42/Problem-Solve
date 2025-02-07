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

    freopen("input.txt", "r", stdin);

    // for(int t = 0; t < 100; t++){

    string exp;
    cin >> exp;

    // string ans;
    // cin >> exp >> ans >> ans;

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

                if(c == ')'){
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

//     cout << "t: " << t << "\n";
    cout << variable.top() << endl;
//     if(!variable.top().compare(ans)){
//         cout <<  "True\n";
//     }else{
//         cout <<  "False\n";
//     }
//     cout << "---------------------\n";
//     cout << "\n";
// }

    return 0;
}

/* comments
idea)
- 재귀함수를 이용해 괄호 처리 - 괄호 안에서 일어난 연산은 우선적으로 처리되므로
    - 괄호가 끝날 때 내에 들어온 상태인진 검사 X - 괄호가 있어서 들어왔을거기 때문에


바로 처리할 수 있는 경우
다음
*/
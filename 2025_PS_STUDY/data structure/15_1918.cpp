#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

// 연산자 우선순위 지정
map<char, int> priority = {
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
};

// 해당 charactor가 피연산자인지 연산자인지 구분
bool isCharactor(char c){
    if('A' <= c && c <= 'Z') return true;
    return false;
}

string handleBrakets(string& exp, string& result, int idx){
    stack<char> operStack;
    queue<char> operandQ;
    int length = exp.length();
    while(idx < length){
        char targetCh = exp[idx];

        if(idx = length - 1){   // 마지막 문자인 경우
            
        }

        if(isCharactor(targetCh)){  // 문자가 들어오는 경우
            operandQ.push(targetCh);
        }else if(targetCh == '('){  // 괄호를 만나는 경우
            string tempResult = handleBrakets(exp, result, idx + 1);
            result += tempResult;
        }else if(targetCh == ')'){  // 괄호가 종료되는 경우
            return result;
        }else{
            // 괄호 외 연산자를 만나는 경우
            if(operStack.empty()){  // stack이 비어있는 경우
               operStack.push(targetCh); 
            }else{
                // stack에 이미 연산자가 있는 경우
                if(priority[operStack.top()] >= priority[targetCh]){        // 1) stack에 있는게 연산순위가 더 높거나 같을 때
                    result += operandQ.front();
                    operandQ.pop();
                    result += operandQ.front() + operStack.top();
                    operandQ.pop();
                    operStack.pop();

                    operStack.push(targetCh);
                }else if(priority[operStack.top()] < priority[targetCh]){   // 2) stack에 있는게 연산순위가 더 낮을 때
                    operStack.push(targetCh);
                }
            }
        }
        idx++;
    }
    return result;
};

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    string exp;
    getline(cin, exp);
    
    // solving

    string result;
    result = handleBrakets(exp, result, 0);
    cout << result;

	return 0;
}

/* comments 
idea)
- 재귀함수를 이용해 괄호 처리 - 괄호 안에서 일어난 연산은 우선적으로 처리되므로
    - 괄호가 끝날 때 내에 들어온 상태인진 검사 X - 괄호가 있어서 들어왔을거기 때문에

*/
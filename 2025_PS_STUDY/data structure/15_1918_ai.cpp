#include <bits/stdc++.h>
using namespace std;

// 연산자 우선순위 판단 함수
int getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string &infix) {
    string result;
    stack<char> st;
    
    // 문자열 순회하며 변환
    for (char c : infix) {
        // 피연산자인 경우 바로 출력
        if (isalpha(c)) {
            result += c;
            continue;
        }
        
        // 연산자 처리
        switch (c) {
            case '(':
                st.push(c);
                break;
            case ')':
                // 여는 괄호를 만날 때까지 출력
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop();  // '(' 제거
                break;
            default:  // 일반 연산자
                while (!st.empty() && st.top() != '(' && 
                       getPriority(st.top()) >= getPriority(c)) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
        }
    }
    
    // 스택에 남은 연산자들 처리
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string exp;
    cin >> exp;
    cout << infixToPostfix(exp) << '\n';
    
    return 0;
}

/* 개선사항 설명
1. 단일 스택만 사용하여 알고리즘 단순화
2. getPriority() 함수로 연산자 우선순위 로직 분리
3. switch-case문으로 연산자 처리 로직 명확화
4. 불필요한 변수와 조건문 제거
*/
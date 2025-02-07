#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

map<char, int> operPriority = {
    {'*', 2},
    {'/', 2},
    {'+', 1},
    {'-', 1},
};

int getIdx(char c) {
    return c - 'A';
}

double getOperResult(double a, double b, char c) {
    if (c == '*') return a * b;
    else if (c == '/') return a / b;
    else if (c == '+') return a + b;
    else return a - b;
}

int main() {
    fastio;

    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // solving
    stack<double> variable;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isalpha(c)) {
            variable.push(values[getIdx(c)]);
        }else {
            double tmp = variable.top();
            variable.pop();
            tmp = getOperResult(variable.top(), tmp, c);
            variable.pop();
            variable.push(tmp);
        }
    }


    cout << fixed;
    cout.precision(2);
    cout << variable.top();

    return 0;
}

/* comment - 250208
후위표기식
- 후위표기식으로 만드는 문제랑 헷갈렸음
- 그냥 stack 사용해서 문자 나오면 스택에 넣고, 연산자 나오면 계산해서 다시 스택에 넣으면 되는 문제
- 부동소수점 오류, overflow등 조심할 포인트
*/
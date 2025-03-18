#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == ".") {
            break;
        }
        string filteredLine;
        for (char c : line) {
            if (c == '(' || c == ')' || c == '[' || c == ']') {
                filteredLine += c;
            }
        }
        if (isBalanced(filteredLine)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}

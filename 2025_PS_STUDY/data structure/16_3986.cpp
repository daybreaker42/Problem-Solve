#include <iostream>
#include <stack>
#include <string>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    fastio;

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;

        stack<char> s;
        for (char c : str) {
            if (!s.empty() && s.top() == c) {
                s.pop();
            } else {
                s.push(c);
            }
        }

        if (s.empty()) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

/* comment
*/
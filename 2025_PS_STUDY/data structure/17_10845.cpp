#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<int> q;
    int n;
    cin >> n;
    cin.ignore(); // 버퍼 비우기

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        if (line.substr(0, 4) == "push") {
            int num = stoi(line.substr(5));
            q.push(num);
        } else if (line == "pop") {
            if (q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        } else if (line == "size") {
            cout << q.size() << endl;
        } else if (line == "empty") {
            cout << q.empty() << endl;
        } else if (line == "front") {
            if (q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
            }
        } else if (line == "back") {
            if (q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}

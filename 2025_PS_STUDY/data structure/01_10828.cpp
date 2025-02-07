#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	int n;
    cin >> n;
    stack<int> s;
    while(n-- > 0){
        string command;
        int x;
        cin >> command;
        if(!command.compare("push")){
            cin >> x;
            s.push(x);
        }else if(!command.compare("pop")){
            if(!s.empty()){
                cout << s.top() << "\n";
                s.pop();
            }else{
                cout << "-1\n";
            }
        }else if(!command.compare("size")){
            cout << s.size() << "\n";
        }else if(!command.compare("empty")){
            cout << s.empty() << "\n";
        }else if(!command.compare("top")){
            if(!s.empty()){
                cout << s.top() << "\n";
            }else{
                cout << "-1\n";
            }
        }
    }

	return 0;
}

/* comment - 250208
- stack 작동원리 그대로 구현하면 됨
*/
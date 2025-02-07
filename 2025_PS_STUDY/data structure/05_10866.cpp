#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    deque<int> dq;
    while(n-- > 0){
        string command;
        int x;
        cin >> command;
        if(!command.compare("push_front")){
            cin >> x;
            dq.push_front(x);
        }else if(!command.compare("push_back")){
            cin >> x;
            dq.push_back(x);
        }else if(!command.compare("pop_front")){
            if(!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }else{
                cout << "-1\n";
            }
        }else if(!command.compare("pop_back")){
            if(!dq.empty()){
                cout << dq.back() << "\n";
                dq.pop_back();
            }else{
                cout << "-1\n";
            }
        }else if(!command.compare("size")){
            cout << dq.size() << "\n";
        }else if(!command.compare("empty")){
            cout << dq.empty() << "\n";
        }else if(!command.compare("front")){
            if(!dq.empty()){
                cout << dq.front() << "\n";
            }else{
                cout << "-1\n";
            }
        }else if(!command.compare("back")){
            if(!dq.empty()){
                cout << dq.back() << "\n";
            }else{
                cout << "-1\n";
            }
        }
    }

	return 0;
}

/* comment 250207
- 덱 구현하는 문제
*/
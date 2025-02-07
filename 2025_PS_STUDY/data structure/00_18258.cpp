#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    queue<int> q;
    while(n-- > 0){
        string command;
        cin >> command;
        
        if(!command.compare("push")){
            int num;
            cin >> num;
            q.push(num);
        }else if(!command.compare("pop")){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }else{
                cout << "-1\n";   
            }
        }else if(!command.compare("size")){
            cout << q.size() << "\n";
        }else if(!command.compare("empty")){
            cout << q.empty() << "\n";
        }else if(!command.compare("front")){
            if(!q.empty()){
                cout << q.front() << "\n";
            }else{
                cout << "-1\n";   
            }
        }else if(!command.compare("back")){
            if(!q.empty()){
                cout << q.back() << "\n";
            }else{
                cout << "-1\n";   
            }
        }
    }

	return 0;
}
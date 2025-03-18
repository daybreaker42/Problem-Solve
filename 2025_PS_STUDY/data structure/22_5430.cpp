#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){
    fastio
    int tc;
    cin >> tc;
    while(tc-- > 0){
        int n;
        string func, arr;
        deque<int> dq;
        cin >> func;
        cin >> n;
        cin >> arr;
        // init deque
        string tmp = "";
        for(char ch : arr){
            if(!(ch == '[' || ch == ']' || ch == ',')){
                tmp += ch;
            }else if(ch == ',' || ch == ']'){
                if(tmp.length() > 0){
                    dq.push_back(stoi(tmp));
                    tmp = "";
                }
            }
        }
        // cout << "dq - ";
        // while(!dq.empty()){
        //     cout << dq.front() << " ";
        //     dq.pop_front();
        // }
        // cout << "\n";
        // exec function
        bool reversed = false, success = true;
        for(int i = 0; i < func.length(); i++){
            char c = func[i];
            if(c == 'R'){
                reversed = !reversed;
            }else{
                if(dq.empty()){
                    success = false;
                    break;
                }
                if(!reversed){
                    dq.pop_front();
                }else{
                    dq.pop_back();
                }
            }
        }
        // output result
        if(!success){
            cout << "error\n";
            continue;
        }
        cout << "[";
        while(!dq.empty()){
          if(!reversed){
                cout << dq.front();
                dq.pop_front();
            }else{
                cout << dq.back();
                dq.pop_back();
            }
            if(!dq.empty()){
                cout << ",";
            }
        }
        cout << "]\n";
    }
}

/* comment 250226
그냥 deque 이용해서 받은 함수 수행하면 되는 문제
- 중간중간 error 처리나 예외처리 조심 (stoi()에 빈 문자열 들어가면 안됨)
*/
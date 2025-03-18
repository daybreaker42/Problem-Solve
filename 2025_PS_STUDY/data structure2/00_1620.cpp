#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    // freopen("../../input.txt", "r", stdin);
    fastio
    int n, m;
    cin >> n >> m;
    vector<string> idx_to_name;
    idx_to_name.reserve(n);
    map<string, int> name_to_idx;
    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        idx_to_name.push_back(name);
        name_to_idx[name] = i;
    }

    // solving
    for (int i = 0; i < m; i++){
        string input;
        cin >> input;
        // if(('a' <= input[0] && input[0] <= 'z') || ('A' <= input[0] && input[0] <= 'Z')){
        //     // name input
        //     cout << name_to_idx[input] + 1 << "\n";
        // }else{
        //     cout << idx_to_name[stoi(input) - 1] << "\n";
        // }
        if('0' <= input[0] && input[0] <= '9'){
            cout << idx_to_name[stoi(input) - 1] << "\n";
        }else{
            // name input
            cout << name_to_idx[input] + 1 << "\n";
        }
    }
    
    
    return 0;
}

/* comment - 250302
- c++은 fastio 있어야 시간초과 나지 않고 풀 수 있는 문제
- 입력/출력이 많은 경우, fastio랑 vector의 reserve를 꼭 사용하자..

- 처음엔 알파벳 기준으로 if문 나눴는데, 숫자로 나누는게 더 간편.
*/
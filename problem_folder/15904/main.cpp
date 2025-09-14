#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    string str;
    getline(cin, str);
    
    // solving
    int idx = 0;
    string target = "UCPC";
    bool isSuccess = true;
    for(char c : target){
        idx = str.find(c, idx);
        if(idx < 0){
            isSuccess = false;
            break;
        }
    }
    
    // output
    if(isSuccess){
        cout << "I love UCPC";
    }else{
        cout << "I hate UCPC";
    }

	return 0;
}

/* comment 250521
- cin으로 입력이 안돼서 봐봤는데, 공백이 중간에 있어서 getline으로 입력을 받아야 했다.


*/
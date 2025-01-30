#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int power(int n, int k);

int main() {
	fastio;

	// freopen("input.txt", "r", stdin);
    // cin.ignore();
    string n;
    int base;

    getline(cin, n);
    int idx = n.find_first_of(" ");
    base = stoi(n.substr(idx, n.length() - idx));
    n = n.substr(0, idx);

    // solving
    int result = 0;
    int length = n.length();
    for(int i = 0; i < length; i++){
        if('0' <= n[i] && n[i] <= '9'){
            result += (n[i] - '0') * power(base, length - 1 - i);
        }else{
            result += (n[i] - 'A' + 10) * power(base, length - 1 - i);
        }
    }

    cout << result;

	return 0;
}

int power(int n, int k){
    int result = 1;
    for(int i = 0; i < k; i++){
        result *= n;
    }
    return result;
}

/* comment
- c++에서 string 자르기 > substr()
- string to int > stoi()


- ai 개선 버전 코드가 지림.
    - isdigit()
    - 진법번환 -> 누적곱 사용 가능
*/
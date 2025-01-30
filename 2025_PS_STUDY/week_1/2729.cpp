#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 80

using namespace std;

const bool debug = false;

bitset<81> resultBitset(bitset<80>& b1, bitset<80>& b2);
string trimZeros(const string& str);

int main() {
	fastio;

    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    cin.ignore();   // 처음에 int 입력 후 string 입력이라 필요
    for(int i = 0; i < t; i++){
        string originBin;
        string b1, b2;
        getline(cin, originBin);
        int idx = originBin.find(" ");
        b1 = originBin.substr(0, idx);
        b2 = originBin.substr(idx + 1);
        bitset<SIZE> bin1 = bitset<SIZE>(b1);
        bitset<SIZE> bin2 = bitset<SIZE>(b2);
        
        cout << trimZeros(resultBitset(bin1, bin2).to_string()) << "\n";
    }

	return 0;
}

bitset<81> resultBitset(bitset<SIZE>& b1, bitset<SIZE>& b2){
    bool carry = 0;
    bitset<81> result = bitset<81>(0);
    for(int i = 0; i < SIZE; i++){
        if(b1[i] && b2[i]){
            result[i] = carry;
            carry = 1;
        }else if(!b1[i] && !b2[i]){
            result[i] = carry;
            carry = 0;
        }else{
            result[i] = !carry;
        }
    
    }
    if(b1[SIZE - 1] && b2[SIZE - 1]){
        result[SIZE] = 1;
    }
    return result;
}

string trimZeros(const string& str) {
    size_t first = str.find_first_not_of('0'); // 첫 번째 '0'이 아닌 문자의 위치를 찾음
    if (first == string::npos) return "0"; // 모든 문자가 '0'인 경우 "0"을 반환
    return str.substr(first);
}

/* 배운점
- string 앞뒤 문자열 자르는 함수가 있음
```
string trimZeros(const string& str) {
    size_t first = str.find_first_not_of('0'); // 첫 번째 '0'이 아닌 문자의 위치를 찾음
    if (first == string::npos) return "0"; // 모든 문자가 '0'인 경우 "0"을 반환
    size_t last = str.find_last_not_of('0'); // 마지막 '0'이 아닌 문자의 위치를 찾음
    return str.substr(first, (last - first + 1)); // 앞뒤 '0'을 제거한 부분 문자열을 반환
}
```
*/
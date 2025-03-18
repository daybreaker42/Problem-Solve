#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main(){
    // string s1 = "hello-friends";
    // int st = 1;
    // cout << s1.substr(st, s1.find("-") - st) << endl;   // substr(시작, 길이) - 시작부터 길이만큼
    // cout << s1.substr(s1.find("-"));    // substr(위치) - 위치부터 끝까지
    
    map<int, int> m = {
        {1, 2},
        {3, 4}
    };
    m.clear();
    cout << ++m[1];

}
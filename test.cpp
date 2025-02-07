#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void printStr(string str){
    cout << str << endl;
}

int main() {
    fastio;

    char c = 'a';
    string s = "hello";
    s += c;
    cout << s << endl;
    printStr({c});
}
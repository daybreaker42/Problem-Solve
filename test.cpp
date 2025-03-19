#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

struct node{
    int left = 0;
    int right = 0;
};

int main(){
    // string s1 = "hello-friends";
    // int st = 1;
    // cout << s1.substr(st, s1.find("-") - st) << endl;   // substr(시작, 길이) - 시작부터 길이만큼
    // cout << s1.substr(s1.find("-"));    // substr(위치) - 위치부터 끝까지
    
    vector<node> v1(10);
    for(int i = 0; i < v1.size(); i++){
        cout << "index : " << i << ", left : " << v1[i].left << ", right : " << v1[i].right << endl;
    }

}
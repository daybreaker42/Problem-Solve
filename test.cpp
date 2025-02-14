#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

pair<int, long long> getValue(){
    return {1, 2};
}

struct circle {
    int idx;
    int status;
};

map<int, circle> x_axis;   // {좌표, {원 번호, 상태}} / 상태 : 시작 = 1, 종료 = 2


int main() {
	fastio;
    
    
    // bitset<10> b1;
    // for(int i = 0; i < 16; i++){
    //     b1 = bitset<10>(i);
    //     for(int i = 0; i < 4; i++){
    //         cout << b1[i] << " ";
    //     }    
    //     cout << endl;
    // }
    cout << pow(2, 5);
}
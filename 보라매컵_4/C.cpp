#include <bits/stdc++.h>
#define SIZE 100000
using namespace std;

int food[SIZE];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> food[i];
    }

    // solving
}

/* 250222
기댓값 = 확률 * 보상 총합
확률 = 1/n

dp인듯, 근데 O(N^2) 내로 푸는 법을 모르겠음.
20분남음
*/
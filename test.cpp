#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    fastio;
    
    int n = 5, r = 3; // n과 r 값 설정
    vector<int> v(n);
    vector<bool> selected(n); // r개 선택을 위한 배열
    
    // 벡터 초기화
    for(int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    
    // r개 선택을 위해 뒤에서부터 r개를 true로 설정
    fill(selected.begin() + (n-r), selected.end(), true);
    
    // nPr 구현
    do {
        vector<int> temp;
        // r개 선택
        for(int i = n - 1; i >= 0; i--) {
            // if(selected[i]) temp.push_back(v[i]);
            if(selected[i]){
                cout << 5 - i << " ";
            }
        }
        cout << "\n";
        
        // 선택된 r개로 순열 생성
        // do {
        //     for(int x : temp) cout << x << " ";
        //     cout << "\n";
        // } while(next_permutation(temp.begin(), temp.end()));
        
    } while(next_permutation(selected.begin(), selected.end()));
    
    return 0;
}
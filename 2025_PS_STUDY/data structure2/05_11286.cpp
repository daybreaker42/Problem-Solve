#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x != 0){
            // cout << "pair - " << abs(x) << " / " << x / abs(x) << endl;
            pq.push({abs(x), x / abs(x)});       // {절댓값 값, 부호}
        }else{
            if(!pq.empty()){
                cout << pq.top().first * pq.top().second << "\n";
                pq.pop();
            }else{
                cout << "0\n";
            }
        }
    }

	return 0;
}

/* comment - 250302
- 우선순위 큐 사용, 절댓값에 유의하며 출력하면 되는 문제
- greater 사용해서 오름차순으로 우선순위 큐 정렬했고, 뒤에 부호 정보를 저장해 원래 부호 저장
- 덕분에 의도는 아니었지만 덕분에 '절댓값이 같은 경우 더 작은 수를 제거'하는 조건 만족 (key의 첫번째가 같으면 두번째 검사하는듯)


*/
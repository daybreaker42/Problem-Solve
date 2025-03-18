#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int calculateDateDiffInDay(string start, string end){
    int startMonth = stoi(start.substr(0, start.find("-"))), startDay = stoi(start.substr(start.find("-") + 1));
    int endMonth = stoi(end.substr(0, end.find("-"))), endDay = stoi(end.substr(end.find("-") + 1));

}

int calDateOver(int day, int hour, int minute, string borrowLimit){

}

int calculateFee(string start, string end){

}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int n, fee;
    string borrowLimit;
    cin >> n >> borrowLimit >> fee;
    for(int i = 0; i < n; i++){
        string currDate, currTime, partName, userName;
        cin >> currDate >> currTime >> partName >> userName;
        
    }
	return 0;
}

/* comment - 250312

solving
그냥 날짜 계산..?
map 이용해서 정보 저장 말곤 특별 x
~18:24
*/
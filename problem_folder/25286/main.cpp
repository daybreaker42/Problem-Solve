#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int t; cin >> t;
    map<int, int> monthDays = {
        {1, 31},
        {3, 31},
        {5, 31},
        {7, 31},
        {8, 31},
        {10, 31},
        {12, 31},
        {2, 28},
        {4, 30},
        {6, 30},
        {9, 30},
        {11, 30}
    };
    for (int i = 0; i < t; i++)
    {
        int year, month, date;
        cin >> year >> month;
        date = month;
        // 결국 이전 달의 마지막 날짜를 출력하면 되는 문제
        bool isLeapYear = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
        int prevMonth = (month - 2 + 12) % 12 + 1;   // 0~11로 변환, 1 빼고 mod 12한 다음, 1~12로 변환
        if(prevMonth == 2){
            // 윤년 고려
            cout << year << " " << prevMonth << " " << monthDays[prevMonth] + isLeapYear << "\n";
        }else if(prevMonth == 12){
            // 12월 - 1년 전이므로 year - 1
            cout << year - 1 << " " << prevMonth << " " << monthDays[prevMonth] << "\n";
        }else{
            cout << year << " " << prevMonth << " " << monthDays[prevMonth] << "\n";
        }
    }
    

	return 0;
}

/* comment - 250516



*/
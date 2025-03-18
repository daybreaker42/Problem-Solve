#include <bits/stdc++.h>

using namespace std;

int main(){
    int total, curr;
    cin >> total >> curr;

    double curr_percentage = (double)curr / total;
    curr_percentage *= 24 * 60;
    int hour = curr_percentage / 60;
    curr_percentage -= hour * 60;
    int minute = (int)curr_percentage;

    string ans_hour = to_string(hour), ans_min = to_string(minute);
    if(ans_hour.length() < 2){
        ans_hour = '0' + ans_hour;
    }
    if(ans_min.length() < 2){
        ans_min = '0' + ans_min;
    }

    cout << ans_hour << ":" << ans_min;
    return 0;
}

/* 250222
8분 */
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 26
using namespace std;

const bool debug = false;

bool values[SIZE] = {0};

int main() {
	fastio;
    int tc = 1;
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        memset(values, 0, sizeof(values));
        values[0] = 1;
        int cnt = 1;
        char first, second;
        for(int i = 0; i < n; i++){
            cin >> first;
            cin >> second;
            cin >> second;
            if(values[first - 'a'] != values[second - 'a']){
                if(values[second - 'a'] == 1){
                    cnt++;
                }else{
                    cnt--;
                }
            }
            values[first - 'a'] = values[second - 'a'];
        }
        // solving

        // output

        cout << "Program #" << tc++ << "\n";
        if(cnt == 0){
            cout << "none\n";
        }else{
            for(int i = 0; i < SIZE; i++){
                char value = 'a' + i;
                if(values[i]){
                    cout << value << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
        // cout << "cnt - " << cnt << "\n";
    }

	return 0;
}
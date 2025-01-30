#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 4000

using namespace std;

int arr[4][SIZE] = { 0 };

int main() {
    fastio;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[j][i];
        }
    }

    // solving
    long long result = 0;
    vector<int> ab, cd;
    ab.reserve(n * n);
    cd.reserve(n * n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ab.push_back(arr[0][i] + arr[1][j]);
            cd.push_back(arr[2][i] + arr[3][j]);
        }   
    }
    
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    for(int i = 0; i < ab.size(); i++){
        int target = -ab[i];
        auto range = equal_range(cd.begin(), cd.end(), target);
        result += distance(range.first, range.second);
    }

    // output
    cout << result;

    // cout << "\n\n";
    // for(int i = 0; i < ab.size(); i++){
    //     cout << ab[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i < cd.size(); i++){
    //     cout << cd[i] << " ";
    // }

    return 0;
}
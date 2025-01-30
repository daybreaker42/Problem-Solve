#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000
using namespace std;

int a[SIZE] = {0}, b[SIZE] = {0};

int main() {
    fastio;
    int t, n, m;
    cin >> t >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0){
            a[i] += a[i - 1];
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> b[i];
        if(i > 0){
            b[i] += b[i - 1];
        }
    }

    // solving
    long long ans = 0;
    vector<int> partA, partB;
    partA.reserve(n * n);
    partB.reserve(m * m);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int tmp = 0;
            if(i == 0) tmp = a[j];
            else tmp = a[j] - a[i - 1];
            partA.push_back(tmp);
        }   
    }
    for(int i = 0; i < m; i++){
        for(int j = i; j < m; j++){
            int tmp = 0;
            if(i == 0) tmp = b[j];
            else tmp = b[j] - b[i - 1];
            partB.push_back(tmp);
        }   
    }

    sort(partB.begin(), partB.end());

    for(int i = 0; i < partA.size(); i++){
        auto range = equal_range(partB.begin(), partB.end(), t - partA[i]);
        ans += distance(range.first, range.second);
    }

    // output
    cout << ans;

    return 0;
}
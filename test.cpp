#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;



int main() {
    fastio;
    
    pair<int, int> p1, p2;
    p1 = {1, 3};
    p2 = p1;
    cout << p1.first << " : " << p1.second << "\n";
    cout << p2.first << " : " << p2.second << "\n";

    p1.first = 5;

    cout << p1.first << " : " << p1.second << "\n";
    cout << p2.first << " : " << p2.second << "\n";

    cout << 
}
#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);
    int total = 0;
    string name;
    map<string, int> count;
    while(getline(cin, name)){
        total += 1;
        if(count.find(name) == count.end()){
            count[name] = 1;
        }else{
            count[name] += 1;
        }
    }
    cout << fixed;
    cout.precision(4);
    for(auto k : count){
        int tree_count;
        string tree_name;
        tie(tree_name, tree_count) = k;
        cout << tree_name << " " << (double)tree_count / total * 100 << "\n";
    }

	return 0;
}

/* comment - 250303
- cpp에서 eof 처리 -> while 안에 cin >> 이든 getline()이든 넣으면 됨



*/
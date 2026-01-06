#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

// const bool debug = false;

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);

  int a, b, c;
  while(true){
    cin >> a >> b >> c;
    if(a == b == c == 0) break;
    // sort a, b, c as descending
    if(b < c) swap(b, c);
    if(a < b) swap(a, b);

    if(a == b == c){
      cout << "Equilateral\n";
    }else if(a >= b + c){
      cout << "Invalid\n";
    }else if(a == b || b == c){
      cout << "Isosceles\n";
    }else{
      cout << "Scalene\n";
    }
  }

	// system("pause");
	return 0;
}

/* comment 



*/
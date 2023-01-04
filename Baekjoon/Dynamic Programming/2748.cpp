// BOJ 2748 - �Ǻ���ġ �� 2, 221228 solved
// long long �� array out of bound ����..
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> memory(n + 1, 0);

	// solving
	memory[0] = 0;
	if(n > 0)
		memory[1] = 1;

	for (int i = 2; i <= n; i++) {
		memory[i] = memory[i - 1] + memory[i - 2];
	}

	// output
	cout << memory[n];
	return 0;
}
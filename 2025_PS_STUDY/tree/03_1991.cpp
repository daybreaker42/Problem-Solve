#include <bits/stdc++.h>
#define SIZE 1 << 26
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

char nodes[SIZE];   // 최대 2^n까지 저장 가능하게

// const bool debug = false;

// 트리 전위순회
void printPreOrder(int curr){
    cout << (char)('A' + curr - 1);
    if(nodes[curr * 2]) printPreOrder(nodes[curr * 2]);
    if(nodes[curr * 2 + 1]) printPreOrder(nodes[curr * 2 + 1]);
}

// 트리 중위순회
void printInOrder(int curr){
    if(nodes[curr * 2]) printInOrder(nodes[curr * 2]);
    cout << (char)('A' + curr - 1);
    if(nodes[curr * 2 + 1]) printInOrder(nodes[curr * 2 + 1]);
}

// 트리 후위순회
void printPostOrder(int curr){
    if(nodes[curr * 2]) printPostOrder(nodes[curr * 2]);
    if(nodes[curr * 2 + 1]) printPostOrder(nodes[curr * 2 + 1]);
    cout << (char)('A' + curr - 1);
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);

    int n; 
    cin >> n;
    // map<char, vector<char>> nodes;
    for (int i = 0; i < n; i++){
        char curr, left, right;
        cin >> curr >> left >> right;
        int currIdx = curr - 'A' + 1, leftIdx = left - 'A' + 1, rightIdx = right - 'A' + 1;
        if(left != '.'){
            nodes[currIdx * 2] = leftIdx;
        }
        if(right != '.'){
            nodes[currIdx * 2 + 1] = rightIdx;
        }
    }

    // solving
    printPreOrder(1);
    cout << "\n";
    printInOrder(1);
    cout << "\n";
    printPostOrder(1);
    cout << "\n";
    
	return 0;
}

/* comment - 250313 / 15분
- 전위, 중위, 후위 순회 알 수 있었던 좋은 문제


*/
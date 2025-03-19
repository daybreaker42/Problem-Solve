#include <bits/stdc++.h>
// #include <iostream>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SIZE 1000000
using namespace std;

struct node{
    int left = 0;
    int right = 0;
};

// const bool debug = false;
vector<node> tree(SIZE);

void postOrder(int curr){
    int left = tree[curr].left, right = tree[curr].right;
    if(left > 0) postOrder(left); // 근데 계속 커지고 n = 10000이면 curr는 얼마까지 증가?
    if(right > 0) postOrder(right);
    cout << curr << "\n";
}

int main() {
	fastio;

	// freopen("../../input.txt", "r", stdin);  // 이거 해야함
    int val, root = -1;
    stack<int> s;    // {nodeIdx} 저장
    while(cin >> val){
        if(root < 0) {
            // 루트 노드
            root = val;
            s.push(val);
        }else{
            int t = s.top();
            if(val < t){
                // 숫자가 작음 - 왼쪽 노드
                tree[t].left = val;
                s.push(val);
            }else{
                // 숫자가 큼 - 오른쪽 노드
                s.pop();
                while(!s.empty() && s.top() < val){
                    t = s.top();
                    s.pop();
                }
                tree[t].right = val;
                s.push(val);
            }   
        }
    }

    // solving
    postOrder(root);

	return 0;
}

/* comment - 240319
- 이진 탐색트리를 전위순회한(dfs)결과로 후위순회 결과를 출력해내는 프로그램
- 스택 활용해서 BST 만들어냄
    1) 부모가 없다면(stack -> empty(); = root가 없다면) root 노드로 등록
    2) 부모(t)가 있다면 부모랑 비교
        - t보다 작다면 left node로 등록
        - t보다 크다면 -> t의 right인지 t 부모의 right인지 모름
            - t 부모랑 비교
                - 작은 게 나오거나 stack에 값이 없을 때까지 타고 올라감
                - 작다면(또는 stack이 비었다면) 해당 노드의 right node로 등록
- BST는 1차원배열로 하면 node <= 2^10000이라 불가. vector 만들어서 linked list 형태로 구현.

- eof처리 필요 -> input.txt 만들어 사용

* BST 중위순회 -> 오름차순 정렬임
*/
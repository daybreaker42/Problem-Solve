#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[4][4000];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[j][i];
        }
    }

    // solving
    sort(arr[0], arr[0] + n);
    sort(arr[1], arr[1] + n);
    sort(arr[2], arr[2] + n);
    sort(arr[3], arr[3] + n);

    long long ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int st = 0, ed = 0;
            while(ed < n){
                int val = arr[0][i] + arr[1][j] + arr[2][st] + arr[3][ed];
                if(val == 0){
                    // 4개 고른 합이 0임
                    cout << "ans : " << arr[0][i] << " " <<  arr[1][j] << " " <<  arr[2][st] << " " <<  arr[3][ed] << "\n";
                    ans++;
                    ed++;
                }else if(val < 0){
                    // 4개 고른 합이 0보다 작음
                    ed++;
                }else{
                    // 0보다 큼
                    if(st < ed) st++;
                    else {
                        ed++;
                        st = 0;
                    }
                }
            }
        }
    }
    
    cout << ans;
    // Print sorted sub-arrays for testing
    cout << "\n\n";
    for (int i = 0; i < 4; i++) {
        cout << "arr[" << i << "]: ";
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


/* comment
정답 개수 -> 2*10^14 -> long long으로 해야함

각 배열에서 
- brute force -> 총 가짓수 2*10^14 -> 절대 불가

좀 더 효율적인 방법 필요
- 만약 배열이 두개만 있다고 생각 -> brute force로 가능하지만 더 효율적인 방법 있을 것 -> 

- 배열 3개는 그냥 돌리면서 하나는 이분탐색 -> O(n^3logn)까지 가능
이정도면 가능하나..? n <= 4000 -> n^3logn 이면 
*/
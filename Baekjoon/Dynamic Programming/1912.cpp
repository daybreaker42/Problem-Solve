#include <iostream>
#include <vector>
using namespace std;

void print_arr(vector<int> arr, int n);
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, i, j, max_sum = -1000, tmp, index, length;
    cin >> n;
    vector<int>arr(n);
    index = 0;
    // �Է�
    cin >> arr[0];
    if(arr[0] > max_sum) max_sum = arr[0];
    for(i = 1; i < n; i++){
        cin >> tmp;
        if(tmp > max_sum)   max_sum = tmp;
        if(arr[index] * tmp >= 0){  // >0�̸� ��ȣ ���� ��, ==0�̸� �� �� �ϳ��� 0�϶� -> ���ص� �������.
            arr[index] += tmp;

        }
        else if(arr[index] * tmp < 0){
            arr[++index] = tmp;
        }
    }
    length = index + 1; // ����� �迭 ���� ����
    print_arr(arr, n);
    cout << "\nmax_sum : " << max_sum;

    
    // DP
    // tmp = arr[0];
    // for(i = 1; i < n; i++){
    //     if(arr[i] >= 0){
    //         tmp += arr[i];
    //     }else{
    //         if(max_sum < tmp)
    //             max_sum = tmp;
    //         tmp = 0;
    //     }
            
    // }
    // if(max_sum < tmp)
    //     max_sum = tmp;
    // cout << max_sum;
    return 0;
}
void print_arr(vector<int> arr, int n){
    cout <<"\n�迭 ���\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout <<"\n";
    return;
}
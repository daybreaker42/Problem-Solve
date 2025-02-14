# bitset

## 개요

- `00000` -> 2^5개 정보 표현가능
- 비트는 true/false 두가지로 표현할 수 있는 정보를 저장하기에 효율적 -> 이걸 이용해 문제 해결

## 사용 예시

비트셋은 다양한 문제 해결에 사용될 수 있습니다. 예를 들어, 집합 연산, 비트 마스킹, 그리고 효율적인 메모리 사용이 필요한 경우에 유용합니다.

### 집합 연산

비트셋을 사용하여 집합 연산을 수행할 수 있습니다. 예를 들어, 두 집합의 교집합, 합집합, 차집합을 비트 연산으로 쉽게 구할 수 있습니다.

```cpp
#include <bitset>
#include <iostream>

int main() {
    std::bitset<5> set1("10101"); // 21 in decimal
    std::bitset<5> set2("00111"); // 7 in decimal

    // 교집합
    std::bitset<5> intersection = set1 & set2; // 00101
    std::cout << "Intersection: " << intersection << std::endl; // Intersection: 00101

    // 합집합
    std::bitset<5> union_set = set1 | set2; // 10111
    std::cout << "Union: " << union_set << std::endl; // Union: 10111

    // 차집합
    std::bitset<5> difference = set1 & ~set2; // 10000
    std::cout << "Difference: " << difference << std::endl; // Difference: 10000

    return 0;
}
```

### 비트 마스킹

비트셋을 사용하여 특정 비트를 마스킹할 수 있습니다. 이는 특정 비트를 설정하거나 지우는 데 유용합니다.

```cpp
#include <bitset>
#include <iostream>

int main() {
    std::bitset<8> bits("11001100");

    // 마스크를 사용하여 특정 비트를 설정
    std::bitset<8> mask("00000011");
    bits |= mask; // 11001111
    std::cout << "After setting bits: " << bits << std::endl; // After setting bits: 11001111

    // 마스크를 사용하여 특정 비트를 지움
    bits &= ~mask; // 11001100
    std::cout << "After clearing bits: " << bits << std::endl; // After clearing bits: 11001100

    return 0;
}
```

### 효율적인 메모리 사용

비트셋은 메모리를 효율적으로 사용하여 많은 수의 불리언 값을 저장할 수 있습니다. 이는 메모리 제한이 있는 환경에서 유용합니다.

```cpp
#include <bitset>
#include <iostream>

int main() {
    std::bitset<1000> largeBitset;
    largeBitset.set(); // 모든 비트를 1로 설정
    std::cout << "Number of set bits: " << largeBitset.count() << std::endl; // Number of set bits: 1000

    return 0;
}
```

## 추가 사용법

- string, int 등을 bitset으로 만드는 방법

```cpp
std::string bit_string = "110010";
std::bitset<8> b3(bit_string);       // [0,0,1,1,0,0,1,0]

std::cout << b3.to_string() << std::endl ;
```

```cpp
/* bitset 생성 */
// bitset<6> bit;   // 000000
// bitset<6> bit("110011"); // 문자열 "110011"로 초기화
// bitset<20> bit2(58);  // 10진수 58로 초기화



/* 비트 수정 */
bitset<6> bit("110011");
//bit[5] = 0; // bit.reset(5); // 인수 생략 시 전체 0
//bit[3] = 1; // bit.set(3, 1); // 인수 생략 시 전체 1
//bit[1] = !bit[1]; // bit.flip(1); // 인수 생략 시 전체 반전
cout << bit << "\n";


/* 2진수 문자열 10진수로 변환 */
int n = bit.to_ulong(); // type = unsigned long integer
// int n = bit.to_ullong(); // type = unsigned long long
cout << bit << "를 10진수로 변환 : " << n << "\n";


/* 비트 검사 */
// 모든 비트가 1이면 true, 하나라도 0이 존재하면 false
if (bit.all()) cout << "모두 1이다\n";
else cout << "모두 1이 아니다\n";

// 1이 하나라도 존재하면 true, 그렇지 않으면 false
if (bit.any()) cout << "0이 아니다\n"; 
else cout << "0이다\n";

// 1이 하나라도 존재하면 false, 그렇지 않으면 true
if (bit.none()) cout << "0이다\n";
else cout << "0이 아니다\n";




/* 10진수 숫자 -> 2진수 문자열 */
int num = 62;
bitset<20> bit2(num);
string s = bit2.to_string();
if (bit.any()) {  
    s = s.substr(s.find('1'));
}
else {
    s = "0";
}
cout << num << "를 2진수로 변환 : " <<  s << "\n";


/* bitset 탐색 */
cout << bit2 << "\n";
cout << "비트 중 1의 개수 : " << bit2.count() << "\n"; // 비트 1의 개수
for (int i = 0; i < bit2.size(); i++) { // bitset 전체 길이
    cout << bit2[i] << " "; // 뒤에서부터 접근한다.
}
cout << "\n";


return 0;
```

> 참고 - <https://notepad96.tistory.com/35>

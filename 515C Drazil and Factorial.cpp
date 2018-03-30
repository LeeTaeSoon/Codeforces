/*
C. Drazil and Factorial

Drazil 은 Varda 와 수학게임을 하고 있다.

자리수 팩토리얼의 곱을 양의 정수 x 를 가지는 F(x) 로 정의하자.
예를 들어 F(135) = 1! * 3! * 5! = 720 이다.

먼저 그들은 1 보다 큰 숫자를 하나 이상 포함하는 n 자릿수의 십진수 a 를 고른다.
이 숫자는 0 으로 시작할 수 있다. 그러면 그들은 아래 2 조건을 만족하는 양수 x 의 최댓값을 찾아야 한다.

1. x 는 0 이나 1 을 포함하지 않는다.
2. F(x) = F(a)

이런 숫자를 찾는 것을 도와라.
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  string a;
  cin >> n >> a;

  int arr[10] = { 0, };
  for (int i = 0; i < n; i++) {
    int d = a.at(i) - '0';

    if (d == 4) {
      arr[2] += 2;
      arr[3] += 1;
    } else if (d == 6) {
      arr[3] += 1;
      arr[5] += 1;
    } else if (d == 8) {
      arr[2] += 3;
      arr[7] += 1;
    } else if (d == 9) {
      arr[2] += 1;
      arr[3] += 2;
      arr[7] += 1;
    } else arr[d]++;
  }

  for (int i = 9; i > 1; i--) {
    if (arr[i] > 0)
      while (arr[i]-- > 0) cout << i;
  }
  return 0;
}

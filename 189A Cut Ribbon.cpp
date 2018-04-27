/*
A. Cut Ribbon

Polycarpus 는 길이가 n 인 리본을 가지고 있다. 그는 리본을 아래 두 조건을 만족하는 방법으로 자르고 싶다.

- 자른 후의 각 리본 조각은 a, b, c 길이를 가진다.
- 자른 후의 리본 조각의 개수는 최대가 된다.

Polycarpus 를 도와 요구된대로 절단 한 뒤 리본 조각의 개수를 구하라.
*/
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  int* arr = new int[n + 1];
  arr[0] = 1;
  for (int i = 1; i < n + 1; i++) arr[i] = 0;

  for (int i = 1; i < n + 1; i++) {
    int x = 0, y = 0, z = 0;
    if (i >= a && arr[i - a] > 0) x = arr[i - a] + 1;
    if (i >= b && arr[i - b] > 0) y = arr[i - b] + 1;
    if (i >= c && arr[i - c] > 0) z = arr[i - c] + 1;
    arr[i] = max(x, max(y, z));
  }

  cout << arr[n] - 1;
  return 0;
}

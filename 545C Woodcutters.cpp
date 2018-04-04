/*
C. Woodcutters

Susie 는 매일 자기전에 동화를 듣는다. 오늘의 동화는 목제 절단기에 대한 것이었고 소녀는 바로 나무를 자르는 세단기를 상상하기 시작했다.
그녀는 아래 설명되는 상황을 상상했다.

x1, x2, ..., xn 지점에 도로를 따라 n 개의 나무들이 위치해있다. 각 나무는 hi 높이이다.
목제 절단기는 나무를 자르고 왼쪽이나 오른쪽으로 넘어뜨릴 수 있다. 나무는 [xi - hi, xi] 나 [x1, xi + hi] 만큼의 공간을 차지한다.
잘리지 않은 나무는 xi 의 포인트만 차지한다. 목제 절단기는 나무가 넘어졌을 때 어떤 차지된 point 도 포함하지 않으면 넘어뜨릴 수 있다.
목제 절단기는 가능한 많은 나무를 처리하고 싶다. Susie는 넘어뜨릴수 있는 나무의 최대 갯수가 궁금하다.
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int** arr = new int*[n];
  int* fell = new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[2];
    cin >> arr[i][0] >> arr[i][1];

    fell[i] = 0;
  }

  int* dp  = new int[n];
  dp[0] = 1;
  fell[0] = -1;

  for (int i = 1; i < n - 1; i++) {
    int space = arr[i][0] - arr[i - 1][0];
    if (fell[i - 1] == 1) space -= arr[i - 1][1];

    dp[i] = dp[i - 1] + 1;
    if (space > arr[i][1]) fell[i] = -1;
    else if (arr[i][0] + arr[i][1] < arr[i + 1][0]) fell[i] = 1;
    else dp[i]--;
  }
  if (n < 2) dp[n - 1] = 1;
  else dp[n - 1] = dp[n - 2] + 1;

  cout << dp[n - 1];
  return 0;
}

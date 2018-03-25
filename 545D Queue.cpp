/*
D. Queue

어린 소녀 Susie 는 엄마와 쇼핑을 갔다. 그녀는 어떻게 서비스 질을 향상시키는지 궁금했다.

큐에 n 명의 사람이 있다. 우리는 각 사람에 대해 그를 서비스할 시간을 알고있다.
손님은 기다리는 시간이 서비스 받는 시간보다 길면 실망할 것이다.
손님이 대기하는 시간은 큐에서 그보다 먼저 서있는 모든 사람들이 서비스 받는 시간이다.
우리는 실망하는 손님의 숫자를 줄일 수 있다.

Susie 가 큐에서 순서를 바꾸어 실망하지 않도록 할 수 있는 손님의 최대 숫자를 구하는 것을 도와라.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);

  int wait = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    int serve = arr[i];
    if (wait > serve);
    else {
      sum++;
      wait += serve;
    }
  }

  cout << sum << endl;
  return 0;
}

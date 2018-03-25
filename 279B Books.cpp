/*
B. Books

Valera 가 자유 시간을 가질 때, 그는 도서관에 가서 책을 읽는다. 오늘 그는 t 만큼의 독서할 자유 시간을 가졌다.
그래서 Valera 는 도서관에서 n 개의 책을 가져왔고 책마다 읽는데 필요한 시간을 예상했다.
1 부터 n 까지 책에 번호를 붙여보자.

Valera 는 임의로 i 번째 책을 고르고 이 책부터 하나씩 읽기로 했다.
즉, 그는 i 번째 책을 처음으로 읽고 i + 1, i + 2 번의 책 순서로 읽을 것이다.
그는 자유시간이 끝나거나 n 번째 책을 읽을 때까지 계속할 것이다.
Valera 는 각각의 책을 끝까지 읽는다. 그 말은 만약 그가 끝까지 읽을 시간이 충분하지 않으면 읽지 않는다는 것이다.

Valera 가 읽을 수 있는 책의 최대 갯수를 출력하라.
*/
#include <iostream>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  int* arr = new int[n + 1];
  arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;

    arr[i] = arr[i - 1] + a;
  }

  int max = 0, start = 1, end = 1;
  while (end <= n) {
    if (arr[end] - arr[start - 1] > t) start++;
    else {
      int count = end - start + 1;
      if (count > max) max = count;
      end++;
    }
  }

  cout << max << endl;
  return 0;
}

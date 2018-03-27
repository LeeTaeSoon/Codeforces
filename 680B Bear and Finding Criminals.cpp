/*
B. Bear and Finding Criminals

Bearland 에는 1 부터 n 까지 번호를 가진 n 개의 도시가 있다. 도시들은 한 줄로 길게 배열되어있다.
i 와 j 도시 사이의 거리는 |i - j| 와 같다.

Limak 은 경찰관이다. 그는 a 도시에 산다. 그의 직업은 범죄자들을 잡는 것이다.
이것은 그가 각 도시마다 최대 한 명의 범죄자가 있는걸 알아도 그가 어떤 도시에 범인이 있는지 모르기 때문에 어렵다.


Limak 은 BCD(Bear 범죄 탐지기)를 사용할 것이다. BCD 는 Limak 에게 a 도시에서 모든 거리 안에 범죄자가 얼마나 있는지 알려준다.
그 후 Limak 은 그가 범죄자가 있다고 확신하는 각 도시에서 범죄자를 잡는다.

당신은 어느 도시에 범죄자들이 있는지 안다. Limak 이 BCD 를 사용한 뒤 잡을 범죄자의 수를 계산해라.
*/
#include <iostream>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;

  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  int len = n - a > a - 1 ? n - a : a - 1;

  a--; // -> index
  int sum = arr[a];
  for (int i = 1; i <= len; i++) {
    int count = 0;
    bool l = false, r = false;
    if (a - i < 0) l = true;
    else if (arr[a - i] == 1) {
      l = true;
      count++;
    }

    if (a + i >= n) r = true;
    else if (arr[a + i] == 1) {
      r = true;
      count++;
    }

    if (l && r) sum += count;
  }

  cout << sum << endl;
  return 0;
}

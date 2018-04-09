/*
A. Party

한 회사는 1 ~ n 의 번호를 가진 n 명의 직원이 있다.
각 직원은 직속상관이 없거나 다른 번호를 가진 다른 직원인 직속상관이 정확히 1명 있다.
직원 A 는 아래 내용 중 하나라도 사실이면 다른 직원 B 의 상급자이다.

 - 직원 A 는 직원 B 의 직속 상관이다.
 - 직원 B 는 직속 상관 C 가 있고, A 는 C 의 직속상관이다.

회사는 상급자 사이클을 가지지 않을 것이다. 즉 자신의 직속 상관의 상급자인 직원은 존재하지 않을 것이다.

오늘 회사는 파티를 주선할 것이다. 이것은 모든 n 명의 직원을 몇 그룹으로 나누는 작업을 수반한다.
모든 직원은 반드시 정확히 한 그룹에 속해야 한다.
추가로 어떤 단일 그룹 내에서 B 의 상급자인 A 와 B 가 있어선 안된다.

그룹이 형성되어야 하는 최소 수는 몇 개인가?
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int* parent = new int[n + 1];
  bool* edge = new bool[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> parent[i];
    edge[i] = true;
  }

  for (int i = 1; i <= n; i++) edge[parent[i]] = false;

  int max = 1;
  for (int i = 1; i <= n; i++) {
    if (edge[i]) {
      int h = 0, node = i;
      while (node > 0) {
        node = parent[node];
        h++;
      }

      if (max < h) max = h;
    }
  }

  cout << max;
  return 0;
}

/*
B. Taxi

학생 n 그룹이 수업이 끝난 후 Polycarpus 의 생일을 축하하기 위해 방문했다.
우리는 i 번째 그룹이 si 명의 친구들로 되어있고 (1 <= si <= 4) 그들은 Polycarpus 에게 함께 가기를 원한다.
그들은 택시를 타고 가기로 결정했다. 각 차에는 최대 4 명의 승객을 태울 수 있다.
만약 각 그룹의 모든 멤버들이 같은 택시를 타고 가려면 학생들은 최소 몇 대의 택시가 필요한가? (하나의 택시는 1 그룹 이상을 태울 수 있다.)
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[4] = { 0, };
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[a - 1]++;
  }

  int sum = arr[3];
  int num = min(arr[0], arr[2]);
  arr[0] -= num;
  sum += arr[2];

  sum += (arr[1] + 1) / 2;
  if (arr[1] % 2 > 0) arr[0] -= 2;

  sum += (arr[0] + 3) / 4;

  cout << sum << endl;
  return 0;
}

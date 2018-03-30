/*
B. Amr and Pins

Amr 는 기하학을 좋아한다. 하루는 아주 흥미로운 문제를 찾았다.

Amr 는 중심이 (x, y) 인 반지름 r 인 원을 가지고 있다. 그는 원의 중심을 (x', y') 로 옮기고 싶다.

한 번에 Arm 는 특정 지점에서 원의 경계에 핀을 꽂고 핀을 중심으로 원을 임의의 각도로 회전시키고 핀을 제거할 수 있다.

Amr 이 가장 적은 횟수로 목표를 달성할 수 있도록 도와라.
*/
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  double r, x, y, _x, _y;
  cin >> r >> x >> y >> _x >> _y;

  double distance = sqrt(pow(_x - x, 2) + pow(_y - y, 2));
  cout << ceil(distance / (r * 2));
  return 0;
}

/*
B. Dreamoon and WiFi

Dreamoon 은 숫자로 된 선에서 0 위치에 서있다. Draziol 은 Wi-Fi 를 통해 Dreamoon 의 스마트 폰으로 명령 리스트를 보내고 Dreamoon 은 그걸 따라한다.

각 명령은 2 타입 중 하나이다.

 1. 양의 방향으로 1 유닛 이동, + 로 표시
 2. 음의 방향으로 1 유닛 이동, - 로 표시

하지만 Wi-Fi 상태가 좋지 않아 Dreamoon 의 스마트폰은 몇 가지 명령을 인지하지 못했고 Dreamoon 은 성공적으로 인식했더라도 몇 가지는 틀렸을 수 있다는 것을 안다.
Dreamoon 은 모든 인식된 명령을 따라하고 인식하지 못한 것을 결정하기 위해 공정한 동전을 던지기로 결심했다.
(즉, 그는 0.5 로 같은 가능성으로 음의 방향이나 양의 방향으로 1 유닛 이동한다.)

당신은 Drazil 이 보낸 원본 명령 리스트와 Dreamoon 이 받은 리스트를 받았다.
Dreamoon 이 원래 Drazil 의 명령으로 끝나는 지점에서 끝날 가능성은 얼마인가?
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int fac(int n) {
  int result = 1;
  for (int i = 2; i <= n; i++) result *= i;
  return result;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  double q = 0;
  int p1 = 0, m1 = 0, p2 = 0, m2 = 0;
  for (int i = 0; i < s1.length(); i++) {
    if (s1.at(i) == '+') p1++;
    else m1++;
    if (s2.at(i) == '+') p2++;
    else if (s2.at(i) == '-') m2++;
    else if (s2.at(i) == '?') q++;
  }

  double f = p1 - p2, s = m1 - m2, result = 0;
  if (f < 0 || s < 0);
  else if (q == 0) result = 1;
  else result = fac(q) / (fac(f) * fac(s));

  cout.precision(30);
  cout << result / pow(2, q);
  return 0;
}

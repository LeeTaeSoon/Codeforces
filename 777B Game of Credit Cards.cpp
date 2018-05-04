/*
B. Game of Credit Cards

4 번째 시즌 후 Sherlock 과 Moriary 는 그들 사이의 싸움의 어리석음을 깨닫고 평화로운 신용 카드 게임으로 결쟁을 계속하기로 했다.

이 게임의 룰은 간단하다. 각 플레이어는 가장 좋아하는 n 자리 신용 카드를 가져온다. 그리고 두 플레이어는 그들의 카드에 기록된 숫자에 하나씩 말한다.
두 자리수가 다르면 숫자가 작은 플레이어가 다른 플레이어에게 flick (집게 손가락으로 이마를 침) 맞는다.
예를 들면, 만약 n 이 3, Sherlock 의 카드는 123, Moriarty 의 카드는 321 이면 처음에 Sherlock 은 1 을 말하고 Moriarty 는 3 을 말해서 Sherlock 이 flick 맞는다.
그리고 둘 다 2 를 말해 아무도 맞지 않는다. 마지막으로 Sherlock 은 3 을 말하고 Moriarty 는 1 을 말해 flick 맞는다.

물론 Sherlock 은 그들에게 주어진 순서대로 하나씩 정직하게 말할 것이지만 진짜 악당인 Moriarty 는 속임수를 쓴다.
그는 다른 순서로 숫자를 말할 것이다 (그러나 그는 각 숫자의 전체 등장 횟수를 바꾸진 않는다).
예를 들어 위의 경우 Moriarty 는 속임수 없이 1 2 3 을 말하거나 2 3 1 을 말해 Sherlock 을 2 번 때릴 수 있다.

당신의 목표는 Moriarty 가 맞을 (아무도 flick 을 좋아하진 않음) flick 의 가능한 최소 횟수를 찾고 Sherlock 이 Moriarty 에게 맞을 최대 횟수를 구하는 것이다. 이 두 가지 목표는 다르고 최선의 결과는 다른 방법으로 얻어진다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s1, s2;
  cin >> s1 >> s2;

  int arr1[10], arr2[10];
  for (int i = 0; i < 10; i++) arr1[i] = arr2[i] = 0;
  for (int i = 0; i < n; i++) {
    arr1[s1.at(i) - '0']++;
    arr2[s2.at(i) - '0']++;
  }

  int c = 0, minFlick = 0, maxFlick = 0;
  for (int i = 0; i < 10; i++) {
    minFlick += arr1[i];
    if (minFlick > arr2[i]) minFlick -= arr2[i];
    else minFlick = 0;
  }

  for (int i = 0; i < 10; i++) {
    if (arr2[i] > 0) {
      int a = min(c, arr2[i]);
      c -= a;
      maxFlick += a;
    }

    c += arr1[i];
  }

  cout << minFlick << endl << maxFlick;
  return 0;
}

/*
A. Functions again

Uzhlyandia 에서 또 무슨 일이 있어났다.. 거리에서 폭동이 있었다..
유명한 Uzhlyandia 슈퍼히어라 Shean the sheep 과 Stas the Giraffe 은 상황을 해결하기 위해 호출되었다.
도착했을 때 그들은 시민들이 아래와 같이 정의된 메인 Uzhlyandia 함수 f 의 최대값이 무엇인지 걱정하고 있는 것을 발견했다.

위의 공식에서 1 <= l < r <= n 이 성립해야 한다. 여기서 n 은 메인 Uzhlyandia 배열 a 의 사이즈이고 |x| 는 x 의 절댓값을 뜻한다.
그러나 영웅들은 학교에서 그들의 수학 시간을 제껴서 당신에게 도움을 요청했다.
그들이 주어진 배열 a 에서 모든 가능한 l, r 값중에 f 의 최대값을 계산하는 것을 도와라.
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  int* dp1 = new int[n];
  for (int i = 1; i < n; i++) dp1[i] = abs(arr[i - 1] - arr[i]);

  long long* dp2 = new long long[n];
  dp2[0] = 0;
  for (int i = 1; i < n; i++) {
    if (i % 2 == 1) dp2[i] = dp2[i - 1] + dp1[i];
    else dp2[i] = dp2[i - 1] - dp1[i];
  }

  long long min = 0, max = -1;
  for (int i = 1; i < n; i++) {
    if (min > dp2[i]) min = dp2[i];
    if (max < dp2[i]) max = dp2[i];
  }

  cout << abs(max - min);
  return 0;
}

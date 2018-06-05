/*
D. Flowers

우리는 Mole 의 점심을 위해 Marmot 가 만든 간단한 게임을 보았다.
지금은 Marmot 의 저녁시간이고 우리 모두 알고 있듯이 Marmot 는 꽃을 먹는다.
매 저녁으로 그는 빨간 꽃과 하얀 꽃을 먹는다.
그러므로 저녁은 여러 꽃들의 배열로 나타낼 수 있고 그 중 일부는 하얀색, 다른 일부는 빨간색이다.

그러나 저녁을 맛있게 먹기 위해 룰이 필요하다. Marmot 는 하얀꽃들을 k 크기의 그룹으로만 먹고싶다.

Marmot 는 그가 a, b 꽃들 사이에서 꽃을 먹을 수 있는 방법이 얼마나 많은지 궁금하다.
방법의 수가 너무 많다면 1000000007 의 나머지를 출력하라
*/
#include <iostream>
using namespace std;

int main() {
  int t, k;
  cin >> t >> k;

  int dp[100001] = { 0, };
  dp[0] = 1;

  for (int i = 1; i < 100001; i++) {
    dp[i] = (dp[i - 1] + dp[i]) % 1000000007;
    if (i - k < 0) dp[i] = 1;
    else dp[i] = (dp[i - k] + dp[i]) % 1000000007;
  }

  for (int i = 2; i < 100001; i++) {
    dp[i] = (dp[i - 1] + dp[i]) % 1000000007;
  }

  dp[0] = 0;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;

    if (dp[b] - dp[a - 1] < 0) cout << 1000000007 - dp[a - 1] + dp[b] << endl;
    else cout << (dp[b] - dp[a - 1]) % 1000000007 << endl;
  }

  return 0;
}

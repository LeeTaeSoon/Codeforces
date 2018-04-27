/*
A. Bormdom

Alex 는 지루한걸 좋아하지 않는다. 그게 그가 지루할때 게임을 하는 이유이다.
어느 긴 겨울 저녁 그는 게임을 생각해내고 게임을 하기로 결정했다.

n 개의 정수로 이루어진 시퀀스 a 가 주어진다. 플레이어는 몇 가지 단계를 거친다.
첫 번째 단께에서 그는 시퀀스의 한 요소(ak 라 하자)를 고를 수 있고 삭제하고 ak + 1 과 ak - 1 에 해당하는 요소들도 모두 시퀀스에서 삭제해야 한다.
이 과정은 플레이어에게 ak 포인트를 준다.

Alex 는 완벽주의자이기에 가능한 많은 포인트를 얻기로 결심했다. 그를 도와라.
*/
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int max = 0;
  int arr[100001] = { 0, };
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr[a]++;
    if (a > max) max = a;
  }

  long long* dp = new long long[max + 1];
  for (int i = 0; i < max + 1; i++) dp[i] = 0;
  dp[1] = arr[1];

  for (int i = 2; i < max + 1; i++) {
    long long pre = dp[i - 1];
    long long cur = dp[i - 2] + (long long) arr[i] * i;
    if (cur > pre) dp[i] = cur;
    else dp[i] = pre;
  }

  cout << dp[max];
  return 0;
}

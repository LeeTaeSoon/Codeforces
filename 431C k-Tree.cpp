/*
C. k-Tree

꽤 최근에 창의적인 학생 Lesha 는 tree 에 대한 강의를 들었다.
강의 후 Lesha 는 영감을 받아 k-tree 라 부르는 그의 tree 를 만들었다.

k-tree 는 무한한 루트를 가지는 tree 이다.

 - 각 노드는 k 개의 자식을 가진다.
 - 각 선은 어떤 가중치를 가진다.
 - 만약 우리가 어떤 노드에서 그것의 자식으로 가는 선을 볼 때 (정확히 k 선들), 그들의 가중치는 1, 2, 3, ..., k 이다.

아래 그림은 3-tree 의 일부를 보여준다.

Lesha 친구 Dima 는 이 tree 에 대해 알자마자 궁금해졌다. "k-tree 의 root 에서 출발했을 때 가중치의 총합이 n 이고 최소 d 이상의 가중치 선을 하나 이상 포함하는 경로가 몇 개인가?"
Dima 가 그의 질문에 대한 답을 찾는 것을 도와라. 길의 개수가 너무 커질 수 있기에 1000000007 (10^9 + 7) 의 나머지를 출력하라.
*/
#include <iostream>
using namespace std;

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  long long dpAll[101] = { 0, };
  long long dpD[101] = { 0, };
  long long dp[101] = { 0, };
  dpAll[0] = 1;
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    long long sum = 0;

    for (int j = 1; j <= k && j <= i; j++) {
      if (j >= d) sum += dpAll[i - j];
      else sum += dpD[i - j];

      if (j >= d) dpD[i] += dpAll[i - j];
      else dpD[i] += dpD[i - j];

      dpAll[i] += dpAll[i - j];
    }

    dpD[i] %= 1000000007;
    dpAll[i] %= 1000000007;

    dp[i] = sum;
  }

  cout << dp[n] % (1000000007);
  return 0;
}

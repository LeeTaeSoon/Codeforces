/*
B. Bakery

Masha 는 그녀의 1 부터 n 까지 숫자를 가진 n 개의 도시 중 하나에 빵집을 오픈하고 머핀을 만들길 원한다.
m 개의 양방향 도로는 몇 개의 도시들을 연결하고 있다.

그녀의 빵집에서 머핀을 만들기 위해 Masha 는 몇몇 저장고에서 밀가루 공급을 받아햐한다.
a1, a2, ..., ak 의 다른 도시들에 위치한 k 개의 저장고가 있다.

불행히도 Masha 가 살고 있는 나라의 법은 저장고가 위치한 도시에 빵집을 오픈하는 것을 금지한다.
그녀는 오직 n - k 개의 도시 중 하나에서만 오픈할 수 있고 물론 밀가루 배달은 비용이 든다 - 저장고와 빵집 사이의 1 킬로미터 당 1 ruble 을 내야한다.

만약 그녀가 어떤 도시 b (모든 1 <= i <= k 에 대해 ai != b) 에서 빵집을 오픈하고,
어떤 도시 s (어떤 1 <= j <= k 에 대해 s = aj) 의 저장고를 선택하고,
b 와 s 사이에 합이 x 길이만큼의 도로로 연결되어 있다면 (만약 여러 경로가 존재한다면 Masha 는 어떤 것이든 선택할 수 있다) Masha 는 x rouble 을 내야한다.

Masha 는 절약적이고 합리적이다. 그녀는 빵집을 오픈할 수 있고 (그리고 k 개의 저장고 중 하나와 빵집이 있는 도시와 저장고가 있는 도시 사이의 경로 중 하나를 선택한다.)
배달에 최소한의 ruble 을 낼 수 있는 도시에 관심을 가진다. Masha 가 이 비용을 구하는 것을 도와라.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> vec;
vector<int> storage;
int _min = 1000000001;
bool sto[1000001];

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vec.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    vec[u].push_back(make_pair(v, l));
    vec[v].push_back(make_pair(u, l));
  }

  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    storage.push_back(a);
    sto[a] = true;
  }

  for (int i = 0; i < storage.size(); i++) {
    int a = storage[i];

    for (int j = 0; j < vec[a].size(); j++) {
      int c = vec[a][j].second;

      if (sto[vec[a][j].first]) continue;
      if (_min > c) _min = c;
    }
  }

  if (_min == 1000000001) _min = -1;
  cout << _min;
  return 0;
}

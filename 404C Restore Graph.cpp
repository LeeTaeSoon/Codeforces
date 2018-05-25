/*
C. Restore Graph

Valera 는 n 개의 vertice 로 구성된 셀프 루프와 다중 edge 가 없는 undirected connected graph 를 가지고 있다.
이 그래프는 흥미로운 성질을 가지고 있는데 각 vertices 에 인접한 edge 가 최대 k 개인 것이다.
편의성을 위해 이 그래프의 vertices 가 정수 1 ~ n 으로 인덱싱되어있다고 가정한다.

그러므로 배열의 d[i] 의 원소는 Valera 가 고른 vertex 에서 i 번 vertex 의 최단 거리를 보인다.
어느 날 Valera 는 그래프 vertices 하나에서 다른 모든 곳으로 가는 최단거리를 계산해 배열 d 에 적었다.

그리고 뭔가 돌이킬 수 없는 끔찍한 일이 일어났다. Valera 가 초기 그래프를 잃어버렸다.
그러나 그는 여전히 배열 d 를 가지고 있다. 그가 잃어버린 그래프를 복구하는 것을 도와라
*/
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> vec;
  vec.resize(n);

  for (int i = 1; i < n + 1; i++) {
    int a;
    cin >> a;
    vec[a].push_back(i);
  }

  int cnt = 0;
  vector<pair<int, int>> edges;
  if (vec[0].size() != 1) cout << -1;
  else {
    for (int i = 1; i < n; i++) {
      vector<int> pre = vec[i - 1];
      vector<int> now = vec[i];

      // don't have the graph
      if (pre.size() * k < now.size()) {
        cout << -1;
        return 0;
      }

      for (int j = 0; j < now.size(); j++) {
        int nowVertex = now[j];
        int preVertex;
        if (i == 1) preVertex = pre[j / k];   // root doesn't have an edge with its pre vertex
        else if (k > 1) preVertex = pre[j / (k - 1)];
        else {
          cout << -1;
          return 0;
        }

        cnt++;
        edges.push_back(make_pair(preVertex, nowVertex));
      }
    }

    cout << cnt << endl;
    for (int i = 0; i < edges.size(); i++) cout << edges[i].first << " " << edges[i].second << endl;
  }

  return 0;
}

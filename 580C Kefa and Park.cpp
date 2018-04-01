/*
C. Kefa and Park

Kefa 는 레스토랑에서 첫 높은 월급을 축하하기로 했다.

그는 특이한 공원에 살고있다. 이 공원은 지점 1 에 루트가 있는 N 개의 지점들로 구성된 루트를 가지는 트리이다.
지점 1 은 Kefa 의 집을 포함한다. 아쉽게도 공원에는 고양이도 있다. Kefa 는 이미 어떤 지점에 고양이들이 있는지 알고 있다.

공원의 리프 지점들은 레스토랑을 가지고 있다. Kefa 는 그가 갈 레스토랑을 고르고 싶지만 그는 고양이를 매우 무서워한다.
그래서 그의 집에서 레스토랑까지 갈 길에 고양이가 있는 m 개의 연속적인 점이 없어야 한다.

당신이 할 일은 Kefa 가 레스토랑에 갈 수 있는 길의 수를 세는 것이다.
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int* cats;
vector<int> edge[100001];

int dfs(int vertex, int cat) {
  if (cats[vertex]) cat++;
  else cat = 0;
  if (cat > m || cats[vertex] < 0) return 0;
  cats[vertex] = -1;

  int restaurant = 0;

  for (int i = 0; i < edge[vertex].size(); i++)
      restaurant += dfs(edge[vertex][i], cat);

  if (vertex > 1 && edge[vertex].size() < 2) restaurant = 1;
  return restaurant;
}

int main() {
  cin >> n >> m;
  cats = new int[n + 1];
  for (int i = 1; i <= n; i++) cin >> cats[i];

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }

  cout << dfs(1, 0);
  return 0;
}

/*
A. Xor-tree

Iahub 은 그의 최근 발견인 propagating tree 를 자랑스러워 한다.
지금 그는 새로운 xor-tree 라 불리는 새로운 tree 를 발명했다.
이 새로운 혁명적인 발견 뒤 그는 xor-trees 를 사용한 아이들을 위한 게임을 발명했다.

이 게임은 1 ~ n 의 번호를 가진 n 개의 노드들을 가진 tree 에서 이루어진다.
각 노드 i 는 0 이나 1 의 초기값 initi 를 가진다. tree 의 root 는 1 번 node 이다.

한 명은 게임동안 tree 에 몇가지 (0 가능) 작업을 수행할 수 있다.
작업의 종류는 node x 를 집는 것 하나 뿐이다.
누군가 node x 를 집은 바로 직후, node x 의 값은 반전되고 x 의 아들 값은 동일하게 유지되며 x 의 아들의 아들의 값은 반전되고 x 의 아들의 아들의 아들의 값은 동일하게 유지된다.

게임의 목표는 각 노드 i 가 0 이나 1 의 GOALi 값을 가지게 하는 것이다.
당신은 최소 작업 횟수로 게임의 목표를 달성해야 한다.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> vec;
int* init;
int* goal;
vector<int> flipCount;

void dfs(int node, int parent, int f, int s) {
  if ((init[node] + f) % 2 != goal[node]) {
    flipCount.push_back(node);
    f = (f + 1) % 2;
  }

  for (int i = 0; i < vec[node].size(); i++)
    if (vec[node][i] != parent) dfs(vec[node][i], node, s, f);
}

int main() {
  int n;
  cin >> n;
  vec.resize(n + 1);
  init = new int[n + 1];
  goal = new int[n + 1];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) cin >> init[i];
  for (int i = 1; i <= n; i++) cin >> goal[i];

  dfs(1, 0, 0, 0);

  cout << flipCount.size() << endl;
  for (int i = 0; i < flipCount.size(); i++) cout << flipCount[i] << endl;
  return 0;
}

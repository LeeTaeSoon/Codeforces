/*
B. Cthulhu

옛날에 한 남자가 바다에 왔다. 그 바다는 폭풍우가 치고 어두웠다.
그 남자는 작은 인어가 나타나길 기대하며 불렀지만 나타난건 Cthulhu 였다.

세계의 반대편 끝에서 펜타곤은 몬스터의 행동을 예측하기 위해 정보를 모으려 노력하고 비밀 병기를 준비하고 있었다.
강한 지진 활동과 악기상의 영향으로 위성은 몬스터에게 정확하게 공격을 맞출 수 없다.
첫 번째 발사를 분석한 결과 n 개의 정점과 m 개의 선을 가진 방향이 없는 그래프가 나타났다.
이제 세계 최고의 지식인들이 이 그래프가 Cthulhu 로 간주될지 아닐지 결정하려고 한다.

단순하게 하기 위해 우주에서 Cthulhu 는 촉수가 달린 구형 몸체와 같이 보인다고 가정한다.
형식적으로 우리는 Cthulhu 를 3 개 또는 더 많은 간단한 사이클로 연결된 root 를 가진 trees 들의 집합으로 간주할 것이다.

그래프는 다중 엣지나 self-loop 가 없다.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> vec;
vector<int> chain;
bool isChain[101] = { false, };
bool visit[101] = { false, };
int c = -1;

void dfs(int node, int pre) {
  visit[node] = true;

  for (int i = 0; i < vec[node].size(); i++) {
    int a = vec[node][i];
    if (a == pre) continue;
    if (visit[a]) c = a;
    else dfs(a, node);

    if (c > 0) {
      chain.push_back(node);
      isChain[node] = true;
      if (c == node) c = -2;
      return;
    }

    if (c == -2) return;
  }
}

bool cthulhu(int node, int pre) {
  visit[node] = true;

  for (int i = 0; i < vec[node].size(); i++) {
    int a = vec[node][i];
    if (a == pre) continue;
    if (visit[a] || isChain[a]) return false;
    else if (!cthulhu(a, node)) return false;
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  vec.resize(n + 1);

  int start;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  bool b = true;
  int chainEdge = 0;

  dfs(1, 0);
  for (int i = 0; i < 101; i++) {
    if (isChain[i]) visit[i] = true;
    else visit[i] = false;
  }

  for (int i = 0; i < chain.size(); i++) {
    for (int j = 0; j < vec[chain[i]].size(); j++) {
      if (isChain[vec[chain[i]][j]]) chainEdge++;
      else if (!cthulhu(vec[chain[i]][j], chain[i])) b = false;
    }
  }

  for (int i = 1; i <= n; i++) if (!visit[i]) b = false;

  if (b && chain.size() > 2 && chain.size() * 2 == chainEdge) cout << "FHTAGN!";
  else cout << "NO";
  return 0;
}

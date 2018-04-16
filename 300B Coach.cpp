/*
B. Coach

프로그래밍 코치는 가르칠 학생이 n 명이 있다. 우리는 n 이 3 으로 나눠지는 것을 안다.
모든 학생은 1 ~ n 까지 숫자를 가지고 있다고 가정하자.

대학 프로그래밍 챔피언쉽 전에 코치는 모든 학생을 3 명씩 그룹을 짓고싶다.
우리는 일부 학생들이 서로 같은 팀이 되고 싶어하는 것을 알고있다.
게다가 i 번째 학생이 j 번째 학생과 같은 팀이 되고 싶어한다면 j 번째 학생 또한 i 번째 학생과 같은 팀이 되고 싶어한다.
코치는 팀이 좋은 결과를 보여주길 바라기 때문에 그는 다음과 같은 조건을 유지하고 싶다.
만약 i 번째 학생이 j 번째 학생과 같은 팀이 되고 싶어한다면 i 번째와 j 번째 학생들은 같은 팀이 되어야 한다.
또한 각 학생들은 정확히 한 팀이 되어야 한다.

코치를 도와 그가 원하는 대로 팀을 나누어라.
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> vec;
vector<int> fvec;
vector<vector<int>> svec;
vector<vector<int>> tvec;
int one = 0, two = 0, three = 0;
bool* visit;
int cnt = 0;

void dfs(int node) {
  if (visit[node]) return;
  visit[node] = true;
  cnt++;
  if (cnt == 4) return;

  for (int i = 1; i <= vec[node].size(); i++) dfs(vec[node][i]);

  if (cnt == 1) fvec[one] = node;
  else if (cnt == 2) svec[two].push_back(node);
  else if (cnt == 3) tvec[three].push_back(node);
}

int main() {
  cin >> n >> m;

  vec.resize(n + 1);
  visit = new bool[n + 1];
  for (int i = 0; i <= n; i++) visit[i] = false;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    dfs(i);
    switch (cnt) {
      case 1:
        one++;
        break;
      case 2:
        two++;
        break;
      case 3:
        three++;
        break;
      case 4:
        cout << -1;
        return 0;
    }

    cnt = 0;
  }

  for (int i = 0; i < one; i++) {
    for (int j = 0; j < 3; j++)
      cout << tvec[i][j] << " ";
    cout << endl;
  }

  for (int i = 0; i < two; i++)
    cout << svec[i][0] << " " << svec[i][1] << endl;

  for (int i = 0; i < three; i++)
    cout << fvec[i] << endl;

  return 0;
}

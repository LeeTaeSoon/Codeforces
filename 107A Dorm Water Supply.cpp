/*
A. Dorm Water Supply

독일 대학의 카이로 (GUC) 기숙사는 1 부터 n 까지 숫자가 정해져있다.
지하의 수도관들은 기숙사들을 연결한다. 각 수도관은 특정 방향 (물은 이 방향으로만 흐를 수 있고 반대로 흐르지 못함), 지름 (물이 흐를 수 있는 최대 양의 특성) 이 있다.

각 집에는 최대 하나의 파이프가 들어가고 최대 한개의 파이프가 나온다.
새 학기가 시작되고 GUC 학생이자 기숙사에 사는 Lulu 는 기숙사에 탱크와 수도꼭지를 설치하려고 한다.
나가는 파이프가 있고 들어오는 파이프가 없는 모든 집들을 위해 Lulu 는 물탱크를 설치해야 한다.
각 탱크각 있는 집은 파이프로 연결된 모든 집들에 물을 운반한다.
따라서 각 수도꼭지가 있는 집은 어떤 탱크가 있는 집으로부터 온 물을 받는다.

1주일 후 파이프가 파열되는 것을 막기 위해서 (지난 학기와 같이) Lulu 는 파이프의 지름 또한 고려해야 한다.
각 탱크가 운반하는 물의 양은 탱크와 해당하는 수도꼭지를 연결하는 파이프의 지름을 초과해서는 안된다.
Lulu 는 각 탱크가 해당하는 수도꼭지로 안전하게 물을 운반할 수 있는 최대 물의 양을 찾고 싶다.
*/
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> pipe[1001];
bool visit[1001];
vector<vector<int>> result;
int cnt = 0;

int main() {
  int n, p;
  cin >> n >> p;

  int dsu[1001] = { 0, };

  for (int i = 0; i < p; i++) {
    int a, b, d;
    cin >> a >> b >> d;

    pipe[a] = make_pair(b, d);
    dsu[a]++;
    dsu[b]--;
  }

  result.resize(1000);

  for (int i = 1; i <= n; i++) {
    if (dsu[i] < 1) continue;

    int min = 10000000;
    int node = i;

    while (dsu[node] > -1) {
      if (visit[node]) {
        min = 10000000;
        break;
      }
      if (pipe[node].second < min) min = pipe[node].second;
      visit[node] = true;
      node = pipe[node].first;
    }

    if (min < 10000000) {
      result[cnt].push_back(i);
      result[cnt].push_back(node);
      result[cnt++].push_back(min);
    }

    visit[i] = true;
  }

  cout << cnt << endl;
  for (int i = 0; i < cnt; i++)
    cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;

  return 0;
}
